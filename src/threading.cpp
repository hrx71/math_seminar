#include "../include/matrix.hpp"
#include "../include/vec.hpp"
#include "modularGauss.cpp"
#include "read_matrix.cpp"
#include "read_vector.cpp"
#include <cassert>
#include <condition_variable>
#include <deque>
#include <functional>
#include <future>
#include <gmpxx.h>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

using namespace std;
template<typename T>
struct ThreadPool
{
  public:
    // Moved to public to get access for break condition!!
    //    std::condition_variable cv;
    bool finished;
    using Job = std::packaged_task<T()>;
    ThreadPool(unsigned int nof_threads)
      : finished(false)
      , active(0)

      , threads(nof_threads)
    {
	for (auto& t : threads) {
	    t = std::thread([=]() { process_jobs(); });
	}
    }
    ~ThreadPool()
    {
	{
	    std::unique_lock lock(mutex);
	    finished = true;
	}
	cv.notify_all();
	for (auto& t : threads) {
	    t.join();
	}
    }
    template<typename Task>
    std::future<T>
    submit(Task task)
    {
	Job job(task);
	auto result = job.get_future();
	std::unique_lock lock(mutex);
	jobs.emplace_back(std::move(job));
	cv.notify_one();
	return result;
    }

  private:
    unsigned int active;
    std::vector<std::thread> threads;
    std::mutex mutex;
    std::condition_variable cv;
    std::deque<Job> jobs;

    void
    process_jobs()
    {
	for (;;) {
	    Job job;
	    /* fetch job */
	    {
		std::unique_lock lock(mutex);
		while (jobs.empty() && (active > 0 || !finished)) {
		    cv.wait(lock);
		}
		if (jobs.empty() || finished)
		    break;
		job = std::move(jobs.front());
		jobs.pop_front();
		++active;
	    }
	    /* execute job */
	    job();
	    {
		std::unique_lock lock(mutex);
		--active;
	    }
	}
	/* if one thread finishes, all others have to finish as well */
	cv.notify_all();
    }
};

int
main()
{
    std::string base = "../data/matrix6.txt";
    Matrix M = read_matrix_from_file(base);
    std::vector<std::future<int>> results;

    //   int nof_threads = thread::hardware_concurrency() - 1;
    ThreadPool<int> pool(1);

    size_t nof_jobs = 50;
    size_t nof_checks = 30;

    Vector p = read_vector_from_file("../include/primes32bit.txt", nof_jobs);

    mpz_t prodprim;
    mpz_init_set_ui(prodprim, 1);

    for (size_t i = 0; i < nof_jobs - 1; ++i) {
	mpz_mul_ui(prodprim, prodprim, p(i));
    }

    Vector v(nof_checks); // need some check
    Vector gamma(nof_checks);
    mpz_t mp_gmp[nof_checks];
    
    for (size_t i = 0; i < nof_checks; ++i) {
	mpz_init_set_ui(mp_gmp[i], 0);
    }

    std::cout << "Job returned :" << endl;
    for (size_t i = 0; i < nof_jobs; ++i) {
	results.emplace(results.begin() + i, pool.submit([&, i]() -> size_t {
	    return modular_determinant_thread(M, p(i));
	}));
    }

    //-----------------------------------------------------------------
    //Calculation of the mixed tadix coefficients. Need to be
    //il doit etre implemente dans une fonction
    v(0) = results[0].get();
    mpz_t zw;
    mpz_t mj;
    mpz_t vj;
    mpz_t uk;
    mpz_t gammak;
    mpz_init_set_si(zw, 0);
    mpz_init_set_si(mj, 0);
    mpz_init_set_si(vj, 0);
    mpz_init_set_si(uk, 0);
    mpz_init_set_si(gammak, 0);

    for (size_t k = 1; k < nof_checks; ++k) {
	mpz_set_ui(mp_gmp[0], p(0));
	//Calculation of gamma
	if (k > 1) {
	    mpz_mul_ui(mp_gmp[k-1], mp_gmp[k - 2], p(k-1));
	}
	gamma(k-1) = multinverse(modulo_mp(mp_gmp[k-1], p(k)), p(k));
	
	// int tmp = v(k - 1);
	mpz_set_si(zw, v(k - 1));

	for (ptrdiff_t j = k - 2; j > -1; --j) {

	    // DO: tmp = tmp * m(j) + v(j);
	    mpz_set_si(mj, p(j));

	    mpz_mul(zw, zw, mj);
	    mpz_set_si(vj, v(j));
	    mpz_add(zw, zw, vj);
	}
	// for the negativ representation
	// DO: v(k) = modulo((u(k) - tmp) * gamma(k - 1), m(k));
	mpz_set_si(uk, results[k].get());
	mpz_sub(zw, uk, zw);
	mpz_set_si(gammak, gamma(k - 1));
	mpz_mul(zw, zw, gammak);
	v(k) = modulo_mp(zw, p(k));
	if (v(k) == 0) {
	    pool.finished = true;
	    cout<<endl;
	    cout << "!!-> Abbruchbedingung erfüllt bei k= " << k << "<-!!"<<endl;
	    break;
	}
    }

    std::thread::id this_idd = std::this_thread::get_id();
    cout << "thread_idd" << this_idd << endl;
    cout << "finished" << endl;
    // CLEARING
    mpz_clear(zw);
    mpz_clear(mj);
    mpz_clear(vj);
    mpz_clear(uk);

    for (size_t i = 0; i < nof_checks; ++i) {
	mpz_clear(mp_gmp[i]);
    }
}

