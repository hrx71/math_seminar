#include <stdlib.h>
/**
 * @brief Modulo that can handle negative input
 *
 * @param a integer number
 * @param p prime number
 * @return int residuum
 */
size_t modulo(ptrdiff_t a, size_t p)
{
    int r = (a % p + p) % p;
    return r;
}

size_t modulo_mp(mpz_t a, size_t p){
    // result = (a % p + p) % p;
    mpz_t tmp;
    mpz_init(tmp);
    mpz_mod_ui (tmp, a, p);

    mpz_t tmp2;
    mpz_init(tmp2);
    
    mpz_add_ui(tmp2, tmp, p);
    mpz_mod_ui(tmp2, tmp2, p);
    return mpz_get_si(tmp2);
    mpz_clear(tmp);
    mpz_clear(tmp2);
}

ptrdiff_t to_symmetric(size_t a, size_t p)
{
    int r = (a % p + p) % p;
    if (r > p / 2)
    {
        r = -(-r + p);
    }
    return r;
}

void to_symmetric_mp(mpz_t a,mpz_t  prodprim)

{
    
    // result = (a % p + p) % p;
    mpz_mod(a,a, prodprim);
    mpz_add(a,a, prodprim);
    mpz_mod(a,a, prodprim);
    
///////////////
    mpz_t q;
    mpz_init(q);
    mpz_div_ui(q,prodprim,2);
    int compare = mpz_cmp(a,q);
    if(compare==1)
    {
	mpz_sub(a,a,prodprim);

    }
    mpz_clear(q);
}
