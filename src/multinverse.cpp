#include <numeric>
#include <iostream>
using namespace std;

/**
 * @brief Computation of multiplicative inverse with respect to a prime number
 * 
 * @param a imput integer
 * @param b prime number
 * @return int multiplicative inverse
 */
int 
multinverse(int a, int b) 
{
    int m = b;
    int y = 0, x = 1;
 
    if (b == 1)
        return 0;
 
    while (a > 1) {
        // q is quotient
        int q = a / b;
        int t = b;
 
        // m is remainder now, process same as
        b = a % b, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m;
 
    return x;
}
    

