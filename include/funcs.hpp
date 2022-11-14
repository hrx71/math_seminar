#include <iostream>
#include "matrix.hpp"
#include "vec.hpp"
#include <gmpxx.h>
#include "../src/modulo.cpp"
#include "../src/multinverse.cpp"
#include "../src/garner.cpp"
#include "../src/garner_gmp.cpp"
#include "../src/modularGauss.cpp"
#include "../src/read_matrix.cpp"
#include "../src/read_vector.cpp"

using namespace std;

size_t modulo(ptrdiff_t a, size_t b);
size_t modulo_mp(mpz_t a, size_t b);
ptrdiff_t to_symmetric(size_t a, size_t b);
void to_symmetric_mp(mpz_t a, mpz_t b);
ptrdiff_t multinverse(ptrdiff_t a, size_t n);
ptrdiff_t integerCRA(Vector&  m, Vector& u);
void integerCRA_mp(mpz_t sol_mp,Vector& m, Vector& u);
Matrix modular_cramer(Matrix& A, Vector& rhs, const Vector& primes);
Matrix read_matrix_from_file(string filepath);
Vector read_vector_from_file(string filepath, int nof_lines);
Vector modular_determinant(Matrix &A, const Vector &primes);
ptrdiff_t modular_gauss(Matrix& A, size_t p);
