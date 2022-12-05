#include "../include/matrix.hpp"
#include "../include/vec.hpp"
#include "modularGauss.cpp"
#include "read_matrix.cpp"
#include "read_vector.cpp"
#include <cassert>
#include <chrono>
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
    cout << "** This program has different options. The main options are to "
	    "calculate the exact determinant of a square integer matrix and to "
	    "characterize the matrix ( regular or singular)"
	    "solving linear systems of equations and to the determine wheter a "
	    "matrix is singular or regluar. The program is parallelized using "
	    "Multithreading with Master-Worker pattern. The Synchronization is done with promises and future. To represent the determinant, the whole program works with the Big-Integer Library gmp."


	 << endl
	 << endl;
    cout << "Please start to select your application:" << endl;
    cout << "Options are:" << endl
	 << "a) calc. determinant" << endl
	 << "b) solve lse"
	 << endl;

    string application;
    cin >> application;

    cout << application << endl;
    if (application == "calc.") {

	cout << endl
	     << "Please choose your matrix from data(e.g. matrix1)" << endl;

	string matrixs;
	string base = "../data/";

	cin >> matrixs;
	string res = base + matrixs + ".txt";

	cout << endl << "Reading matrix in" << endl;
	Matrix M = read_matrix_from_file(res);

	int nof_threads = thread::hardware_concurrency();
	string parallel_hardw = to_string(nof_threads);

	res = "Yout have " + parallel_hardw +
	      " Threads for the Parallelization  aviable.";
	cout << endl << res << endl << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::vector<std::future<size_t>> results;
	ThreadPool<size_t> pool(nof_threads);

	size_t nof_jobs = 100;
	size_t nord;

	// Auswahl der primzahlen je nach dem, welche Größe von long int zur Verfügung steht.
	// Long int ist die deterministische Größe, da diese die Eingabe für mpz_t ist
	cout << "Checking platform dependant size of long int...\n";
	string path;
	if (sizeof(long) == 8){
		path = "../include/primes64bit.txt";
	} else {
		path = "../include/primes32bit.txt";
	}
	Vector p =
	  read_vector_from_file(path, nof_jobs);
	Vector v(nof_jobs); // need some check
	Vector gamma(nof_jobs);
	mpz_t mp_gmp[nof_jobs];

	for (size_t i = 0; i < nof_jobs; ++i) {
	    mpz_init_set_ui(mp_gmp[i], 0);
	}

	for (size_t i = 0; i < nof_jobs; ++i) {
	    results.emplace(results.begin() + i,
			    pool.submit([&, i]() -> size_t {
				return modular_determinant_thread(M, p(i));
			    }));
	}

	//-----------------------------------------------------------------
	// Calculation of the mixed tadix coefficients. Need to be
	// il doit etre implemente dans une fonction
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

	for (size_t k = 1; k < nof_jobs; ++k) {
	    mpz_set_ui(mp_gmp[0], p(0));
	    // Calculation of gamma
	    if (k > 1) {
		mpz_mul_ui(mp_gmp[k - 1], mp_gmp[k - 2], p(k - 1));
	    }
	    gamma(k - 1) = multinverse(modulo_mp(mp_gmp[k - 1], p(k)), p(k));

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
	    if (v(k) == 0 || ((p(k) - v(k)) == 1)) {
		nord = k;
		pool.finished = true;
		cout << endl;
		cout << "!!-> Abbruchbedingung erfüllt bei k= " << k << "<-!!"
		     << endl;
		break;
	    }
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	cout << endl
	     << "Calculating the determinant from all isomorphic images..."
	     << endl;

	int sol = 0;
	mpz_t sol_mp;
	mpz_init_set_ui(sol_mp, sol);
	mpz_t tmp;
	mpz_init(tmp);
	mpz_t prodprim;
	mpz_init_set_ui(prodprim, 1);

	for (size_t i = 0; i < nord; ++i) {
	    mpz_mul_ui(prodprim, prodprim, p(i));
	}

	for (ptrdiff_t k = nord; k > -1; --k) {
	    // DO complete: sol = sol*m(k) + v(k);
	    // DO-step1  tmp = sol*m(k)
	    mpz_mul_ui(tmp, sol_mp, p(k));

	    // DO-step2 sol = tmp  + v(k)
	    mpz_add_ui(sol_mp, tmp, v(k));
	}
	cout << endl;
	to_symmetric_mp(sol_mp, prodprim);
	cout << endl << endl << "determinant=";
	mpz_out_str(stdout, 10, sol_mp);
	
	if (mpz_cmp_ui(sol_mp,0)==0) 
	{
	    cout << endl << "The Matrix is singular.!" << endl;
	}
	cout << endl << endl << endl;

	// CLEARING
	mpz_clear(zw);
	mpz_clear(mj);
	mpz_clear(vj);
	mpz_clear(uk);
	mpz_clear(tmp);
	mpz_clear(sol_mp);
	mpz_clear(prodprim);

	for (size_t i = 0; i < nof_jobs; ++i) {
	    mpz_clear(mp_gmp[i]);
	}
    } else {
	cout
	  << endl
	  << "!Error----Please choose one of the available application-options"
	  << endl;
    }
}
