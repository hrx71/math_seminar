#include <iostream>
#include "matrix.hpp"
#include "vec.hpp"
#include "../src/modulo.cpp"
#include "../src/multinverse.cpp"
#include "../src/garner.cpp"
#include "../src/init.cpp"
#include "../src/modularGauss.cpp"

using namespace std;

int modulo(int a, int b);
int multinverse(int a,int n);
int integerCRA(Vector&  m, Vector& u);
void init(Matrix& M, int mod, bool modop);
Vector modularGauss(Matrix& A, const int p);
Matrix modular_cramer(Matrix& A, Vector& rhs, const Vector& primes);
