#include <stdlib.h>
/**
 * @brief Modulo that can handle negative input
 *
 * @param a integer number
 * @param p prime number
 * @return int residuum
 */
int modulo(int a, int p)
{
    int r = (a % p + p) % p;
    return r;
}

int to_symmetric(int a, int p)
{
    int r = (a % p + p) % p;
    if (r > p / 2)
    {
        r = -(-r + p);
    }
    return r;
}