#include <funcs.hpp>
#include <iostream>

using namespace std;

/**
 * @brief Implementation of Garner's alogorithm 
 * 
 * Chinese remainder alogrithm to solve congruence system
 * 
 * @param m array of intergers
 * @param u array of integers
 * @param size 
 * @return int 
 */
void integerCRA_mp(mpz_t sol_mp, Vector &m, Vector &u){
    // Step 1- Compute the modular multiplicative inverse gamma[?]
    size_t size = m.m - 1;
    mpz_t mp_gmp[size];
    
    for(size_t i=0; i<size; ++i) {
	mpz_init_set_ui(mp_gmp[i],0);
    }

    Vector mp(size);
    Vector gamma(size);
    Vector v(size);

    for (size_t k = 0; k < size - 1; ++k){
        mp(k) = m(0);
        mpz_set_ui(mp_gmp[k], m(0));
	for (size_t i = 1; i < k + 1; ++i)
        {
	    // DO:  mp(k) *= m(i);
	    mpz_mul_ui(mp_gmp[k],mp_gmp[k],m(i));
        }
	gamma(k) = multinverse(modulo_mp(mp_gmp[k], m(k + 1)), m(k + 1));
    }

    // Step 2- Compute the radix coefficients
    v(0) = u(0);
    mpz_t zw;
    mpz_t mj;
    mpz_t vj;
    mpz_t uk;
    mpz_t gammak;
    mpz_init_set_si(zw,0);
    mpz_init_set_si(mj,0);
    mpz_init_set_si(vj,0);
    mpz_init_set_si(uk,0);
    mpz_init_set_si(gammak,0);

    for (size_t k = 1; k < size; ++k){
        //int tmp = v(k - 1);
        mpz_set_si(zw,v(k-1));
	for (ptrdiff_t j = k - 2; j > -1; --j)
        {

            //DO: tmp = tmp * m(j) + v(j);
	    mpz_set_si(mj,m(j));
	    
	    mpz_mul(zw,zw,mj);
	    mpz_set_si(vj,v(j));
	    mpz_add(zw,zw,vj);
	}

	// for the negativ representation
	//DO: v(k) = modulo((u(k) - tmp) * gamma(k - 1), m(k));
	mpz_set_si(uk,u(k));
	mpz_sub(zw,uk,zw);
	mpz_set_si(gammak,gamma(k-1));
	mpz_mul(zw,zw,gammak);

	v(k) = modulo_mp(zw,m(k));
    }

    // mixed radix representation
    int sol = 0;
    mpz_init_set_ui(sol_mp, sol);
    mpz_t tmp;
    mpz_init(tmp);
        
    for (ptrdiff_t k = size - 1; k > -1; --k){
        //DO complete: sol = sol*m(k) + v(k);
        //DO-step1  tmp = sol*m(k)
        mpz_mul_ui(tmp, sol_mp, m(k));

        //DO-step2 sol = tmp  + v(k)
        mpz_add_ui(sol_mp, tmp, v(k));
    }
    
    //Clearing
    mpz_clear(zw);
    mpz_clear(mj);
    mpz_clear(vj);
    mpz_clear(uk);
    mpz_clear(tmp);
    for(size_t i=0; i<size; ++i) {
	mpz_clear(mp_gmp[i]);
    }
}
