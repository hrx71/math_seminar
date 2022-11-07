#include <iostream>
#include <gmpxx.h>
#include "../include/vec.hpp"
#include "modulo.cpp"
#include "multinverse.cpp"
#include "garner.cpp"

void fact(int n){
    int i;
    mpz_t p;

    mpz_init_set_ui(p, 1); /* p = 1 */
    for (i = 1; i <= n; ++i)
    {
        mpz_mul_ui(p, p, i); /* p = p * i */
    }
    printf("%d!  =  ", n);
    mpz_out_str(stdout, 10, p);
    mpz_clear(p);
}

void test(Vector &v){
    // array von mpz_t anlegen
    mpz_t w[v.m];
    mpz_t p;
    for (int j = 0; j < v.m; ++j)
    {
        // initaliisieren und unsigned integer in mpz_t speichern
        mpz_init_set_ui(w[j], 1); /* p = 1 */
        for (int i = 1; i <= j; ++i)
        {
            mpz_mul_ui(w[j], w[j], i); /* p = p * i */
        }
    }

    for (int j = 0; j < v.m; ++j)
    {
        std::cout << j << "! = ";
        // print von mpz_t
        mpz_out_str(stdout, 10, w[j]);
        std::cout << std::endl;
        mpz_clear(w[j]);
    }
}

void modulo_mp(mpz_t result, mpz_t a, mpz_t p){
    // result = (a % p + p) % p;
    //           ----
    //           tmp
    //           ---------
    //              tmp2
    mpz_t tmp;
    mpz_init(tmp);
    mpz_mod(tmp, a, p);

    mpz_t tmp2;
    mpz_init(tmp2);
    int p_int = mpz_get_si(p);
    mpz_add(tmp2, tmp, p);
    mpz_mod(result, tmp2, p);
    mpz_clear(tmp);
    mpz_clear(tmp2);
}

void integerCRA_mp(mpz_t sol_mp, Vector &m, Vector &u){
    // Step 1- Compute the modular multiplicative inverse gamma[?]
    size_t size = m.m - 1;
    Vector mp(size);
    Vector gamma(size);
    Vector v(size);

    for (size_t k = 0; k < size - 1; ++k){
        mp(k) = m(0);
        for (size_t i = 1; i < k + 1; ++i)
        {
            mp(k) *= m(i);
        }
        // do 99 % 97 --> 2 modular inverse is the same as 99 mod 97 kongruent 2
        // mod 97
        gamma(k) = multinverse(modulo(mp(k), m(k + 1)), m(k + 1));
    }

    // Step 2- Compute the radix coefficients
    v(0) = u(0);

    for (size_t k = 1; k < size; ++k){
        int tmp = v(k - 1);
        for (ptrdiff_t j = k - 2; j > -1; --j)
        {
            tmp = tmp * m(j) + v(j);
        }
        // for the negativ representation
        v(k) = modulo((u(k) - tmp) * gamma(k - 1), m(k));
    }

    // mixed radix representation
    int sol = 0;
    mpz_init_set_ui(sol_mp, sol);
    mpz_t tmp;
    mpz_init(tmp);
        
    for (ptrdiff_t k = size - 1; k > -1; --k){
        // sol = sol*m(k) + v(k);
        // tmp = sol*m(k)
        mpz_mul_ui(tmp, sol_mp, m(k));

        // sol = tmp  + v(k)
        mpz_add_ui(sol_mp, tmp, v(k));
    }
    mpz_clear(tmp);
}

int main(){
    int n;
    Vector v(20);
    v.init();
    test(v);

    std::cout << "test modulo:" << std::endl;
    mpz_t m;
    mpz_init_set_si(m, -14);
    mpz_t p;
    mpz_init_set_ui(p, 17);
    mpz_out_str(stdout, 10, m);
    std::cout << " mod ";
    mpz_out_str(stdout, 10, p);
    std::cout << " = ";
    mpz_t res;
    mpz_init(res);
    modulo_mp(res, m, p);

    mpz_out_str(stdout, 10, res);
    std::cout << std::endl;
    mpz_clear(p);
    mpz_clear(m);
    mpz_clear(res);

    std::cout << "Testing the chinese remainer for multiprecision: \n";
    int size = 6;
    Vector primes(size);
    primes(0) = 7;
    primes(1) = 11;
    primes(2) = 13;
    primes(3) = 17;
    primes(4) = 19;

    // add product of all primes
    primes(size - 1) = 1;
    for (int i = 0; i < size - 1; ++i)
    {
        primes(size - 1) *= primes(i);
    }

    Vector u(5);
    u(0) = 5;
    u(1) = 1;
    u(2) = 4;
    u(3) = 15;
    u(4) = 11;

    mpz_t result;
    mpz_init(result);
    integerCRA_mp(result, primes, u);
    std::cout << "result = ";
    mpz_out_str(stdout, 10, result);
    int result_normal = integerCRA(primes, u);
    std::cout << std::endl;
    std::cout << "normal CRA result = " << result_normal << std::endl;
    mpz_clear(result);

    return 1;
}