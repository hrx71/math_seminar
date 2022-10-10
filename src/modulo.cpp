#include <iostream>

int modulo(int n, int d){
    int r = (n%d + d)%d;
    return r;
}