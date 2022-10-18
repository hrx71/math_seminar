#include <stdlib.h>   
/**
 * @brief Modulo that can handle negative input
 * 
 * @param a integer number
 * @param p prime number 
 * @return int residuum
 */
int
modulo(int a, int p)
{
 int r = (a%p + p)%p;
 // for symmetric representation:
/*    if (r > p/2) {
        r = -(-r + p);
    }*/
    return r;
}
