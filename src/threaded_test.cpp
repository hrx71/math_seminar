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

    int size = 100;

    Vector p = read_vector_from_file("../include/primes32bit.txt", size);

    mpz_t prodprim;

    mpz_init_set_ui(prodprim, 1);

    p(size - 1) = 1;
    for (int i = 0; i < size - 1; ++i) {
	mpz_mul_ui(prodprim, prodprim, p(i));
	p(size - 1) *= p(i);
    }
    size_t nof_checks = 0;
    Vector v(100); // need some check
    Vector mp(100);
    Vector gamma(100);
    std::cout << "Job returned :" << endl;
	for (;;) {
	    for (int i = 0; i < 50; ++i) {
		results.emplace(results.begin() + i,
				pool.submit([&, i]() -> size_t {
				    return modular_determinant_thread(M, p(i));
				    // << det << "and thread_id = " << this_id
				    // << endl;
				}));
	    }
	    //------------------------------------------------------------------
	    //------------------------------------------------------------------
	    //-----------------------------------------------------------------
	    // Calculation of the mixed tadix coefficients. Need to be
	    // implemented into a function

	    size_t length = 15;
	    mpz_t mp_gmp[size];

	    for (size_t i = 0; i < length; ++i) {
		mpz_init_set_ui(mp_gmp[i], 0);
	    }


	    for (size_t k = 0; k < length; ++k) {
		mp(k) = p(0);
		mpz_set_ui(mp_gmp[k], p(0));
		for (size_t i = 1; i < k + 1; ++i) {
		    // DO:  mp(k) *= m(i);
		    mpz_mul_ui(mp_gmp[k], mp_gmp[k], p(i));
		}
		gamma(k) =
		  multinverse(modulo_mp(mp_gmp[k], p(k + 1)), p(k + 1));
	    }
	    
	    /*cout<<"gamma(k)="<<endl;
	    gamma.print();
	    cout<<endl;
	    */
	    // Step 2- Compute the radix coefficients
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

	    for (size_t k = 1; k < length; ++k) {
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
		cout<<"uk"<<endl;
		mpz_out_str(stdout,10,uk);
		cout <<endl;
		mpz_sub(zw, uk, zw);
		mpz_set_si(gammak, gamma(k - 1));
		mpz_mul(zw, zw, gammak);
		//cout << "gammak" <<gamma(k-1)<<" and k"<<k<<endl;

		v(k) = modulo_mp(zw, p(k));
		cout << "v(k)=" << v(k) << endl;
		if (v(k) == 0) {
		    cout << "abbruchbedingung erfüllt bei k= " << k << endl;
		    pool.finished = true;
		    // break;

		    cout << "------->  coefficients:" << endl;
		    v.print();
		    cout << endl;

		    mpz_clear(zw);
		    mpz_clear(mj);
		    mpz_clear(vj);
		    mpz_clear(uk);
		    for (size_t i = 0; i < length; ++i) {
			mpz_clear(mp_gmp[i]);
		    }

		    cout << "im giving up" << endl;
		    goto jump; 
		}
	    }
	}
    /*cout << "------->  coefficients:" << endl;
    v.print();
    cout << endl;

    mpz_clear(zw);
    mpz_clear(mj);
    mpz_clear(vj);
    mpz_clear(uk);
    for (size_t i = 0; i < length; ++i) {
	mpz_clear(mp_gmp[i]);
    }*/
    //----------------------------------------------------------------------
    //######################################################################
    jump:
    std::thread::id this_idd = std::this_thread::get_id();
    cout << "thread_idd" << this_idd << endl;

    cout << "finished" << endl;
}
