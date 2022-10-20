#include <iostream>
#include "matrix.hpp"
#include "vec.hpp"
using namespace std;

int modulo(int a, int b);
int multinverse(int a,int n);
int integerCRA(int* m, int* u, size_t const size);
void init(Matrix& M, int mod, bool modop);
int modularGauss(Matrix& A, const int p);
