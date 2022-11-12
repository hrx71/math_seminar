#include <iostream>
#include <matrix.hpp>
#include <vec.hpp>
#include <gmpxx.h>
/*#include "../src/modulo.cpp"
#include "../src/multinverse.cpp"
#include "../src/garner.cpp"
#include "../src/modularGauss.cpp"
#include "../src/read_matrix.cpp"
#include "../src/read_vector.cpp"*/

using namespace std;

int modulo(int a, int b);
int modulo_mp(mpz_t a, int b);
int to_symmetric(int a, int b);
void to_symmetric_mp(mpz_t a, mpz_t b);
int multinverse(int a,int n);
int integerCRA(Vector&  m, Vector& u);
void integerCRA_mp(mpz_t sol_mp,Vector& m, Vector& u);
Vector modularGauss(Matrix& A, const int p);
Matrix modular_cramer(Matrix& A, Vector& rhs, const Vector& primes);
Matrix read_matrix_from_file(string filepath);
Vector read_vector_from_file(string filepath, int nof_lines);
Vector modular_determinant(Matrix &A, const Vector &primes);
