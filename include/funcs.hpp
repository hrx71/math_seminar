#include <iostream>
#include "matrix.hpp"
#include "vec.hpp"
using namespace std;

int modulo(int a, int b);
int multinverse(int a,int n);
int integerCRA(Vector&  m, Vector& u);
void init(Matrix& M, int mod, bool modop);
Vector modularGauss(Matrix& A, const int p);
