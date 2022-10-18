#include <stdlib.h>   
int
modulo(int a, int b)
{
 int r = (a%b + b)%b;
/*    if (r > b/2) {
        r = -(-r + b);
    }*/
    return r;
}
