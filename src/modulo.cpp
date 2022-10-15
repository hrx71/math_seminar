#include <iostream>

// computo modulo symmetric representation
int modulo_sym(int n, int d){
    int r = (n%d + d)%d;
    /*if (r > d/2) {
        r = -(-r + d);
    }*/
    return r;
}

// compute division with modulo
int division_modulo(int a, int b, int p){
    int invert = multinverse(b, p);
    return (a * invert)%p;
}