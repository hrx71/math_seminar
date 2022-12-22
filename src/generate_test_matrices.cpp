#include "../include/matrix.hpp"
#include "../include/thread_pool.hpp"
#include "../include/vec.hpp"
#include "modularGauss.cpp"
#include "read_matrix.cpp"
#include "read_vector.cpp"
#include <chrono>
#include <gmpxx.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>


using namespace std;

ptrdiff_t power(ptrdiff_t base, int exponent){
	ptrdiff_t res = 1;
	if (exponent == 0){
		return(res);
	} else {
		for (int i = exponent; i > 0; --i){
			res *= base;
		}
	}
	return(res);
}

Matrix vandermonde(Vector& v){
    size_t size = v.m;
    Matrix V(size, size, StorageOrder::RowMajor);
    for (size_t j= 0; j < V.n; ++j){ //loop over columns
        for (size_t i = 0; i < V.m; ++i){//loop over rows
            V(i,j) =  power(v(i),j);
        }
    }
    return V;
}



int main(){
    //n: size of matrix
    size_t n = 16;
    Vector vand(n);
    vand.init();
    cout << "Vandermonde test-matrix mit n = "<< n << " : "<< endl;
    Matrix M = vandermonde(vand);
    M.print();

    cout<<"Analytisch bestimmte Determinante:"<< endl;
    mpz_t det_analyt;
	mpz_init_set_si(det_analyt, 1);
   
    for (size_t j = 0; j < vand.m; ++j){
        for (size_t i = 0; i < j; ++i){
            long int tmp = vand(j) - vand(i);
            mpz_mul_ui(det_analyt, det_analyt, tmp);
        }
    }
    cout << "det analytical = ";
    mpz_out_str(stdout, 10, det_analyt);
    cout << endl;
    mpz_clear(det_analyt);

    string path;
    cout << "Berechnung der Determinante mit Kongruenzmethoden:\n";
    if (sizeof(long) == 8) {
	path = "../include/primes64bit.txt";
    } else {
	path = "../include/primes32bit.txt";
    }
    Vector p = read_vector_from_file(path, 100);
    int nof_threads = thread::hardware_concurrency();
	string parallel_hardw = to_string(nof_threads);
{}

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::vector<std::future<size_t>> results;
	ThreadPool<size_t> pool(nof_threads);

	size_t nof_jobs = 100;
	size_t nord;

	// Auswahl der primzahlen je nach dem, welche Größe von long int zur
	// Verfügung steht. Long int ist die deterministische Größe, da diese
	// die Eingabe für mpz_t ist
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
	// Calculation of the mixed tadix coefficients.
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
		cout << "Break condition met at number of primes = " << k
		     << endl;
		break;
	    }
	}
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
	to_symmetric_mp(sol_mp, prodprim);
	cout << endl << endl << "det congruent =  ";
	mpz_out_str(stdout, 10, sol_mp);

	if (mpz_cmp_ui(sol_mp, 0) == 0) {
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
}
