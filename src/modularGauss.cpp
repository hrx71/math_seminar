#include <cstddef>
#include <funcs.hpp>
#include <iostream>

Vector
modular_backward_substitution(Matrix& R, const int p, Vector& rhs, Vector& pivot)
{
    assert(R.m == R.n); // R needs to be quadratic
    Vector sol(R.n);

    for (int i = R.n - 1; i >= 0; --i) {    // loop over rows from back
	for (int j = i + 1; j < R.n; ++j) { // loop over columns after
	    rhs(pivot(i)) = rhs(pivot(i)) - sol(j) * R(pivot(i), j);
	}

	// modular arithmetic
	int multinv = multinverse(R(pivot(i), i), p);

	// compute solution
	sol(i) = modulo(multinv * rhs(pivot(i)), p);
    }
    return sol;
}

Matrix
matrix_subset(int m1, int n1, Matrix& A, StorageOrder order)
{
    Matrix A1(m1, n1, order);
    for (int i = 0; i < m1; ++i) {
	for (int j = 0; j < n1; ++j) {
	    A1(i, j) = A(i, j);
	}
    }
    return A1;
}

Vector
vector_subset(int index, Matrix& A, bool col)
{
    int size = (col) ? A.m : A.n;
    Vector v(size);
    if (col) {
	for (int i = 0; i < A.m; ++i) {
	    v(i) = A(i, index);
	}
    } else {
	for (int i = 0; i < A.n; ++i) {
	    v(i) = A(index, i);
	}
    }
    return v;
}


/**
 * @brief Perfoming Gauss Elimination modulo an integer and computing
 * determinant
 *
 * @param A Matrix
 * @param p prime number
 * @return int determinant modulo p
 */
int
modularGauss(Matrix& A, const int p)
{
    // create vector v for pivot of size number of rows of A
    Vector v(A.m);
    v.init(); // fill with list of the frm {0, 1, 2, ..., m-1}

    for (int i = 0; i < A.m - 1; ++i) { // loop over rwos
	if (A(v(i), i) == 0) {
	    // find pivot element: find maximum absolute value in this column
	    std::cout << "Pivot!\n";
	    int maxabs = 0;
	    int maxptr = 0;
	    for (int j = i; j < A.m; ++j) {
		if (abs(A(v(j), i)) > maxabs) {
		    maxabs = A(v(j), i);
		    maxptr = j;
		}
	    }
	    // swap pivot vector
	    int tmp = v(i);
	    v(i) = v(maxptr);
	    v(maxptr) = tmp;
	}

	// gauss elimination
	for (int j = i + 1; j < A.m; ++j) { // loop over lower rows
	    int tmp = A(v(j), i);
//	    std::cout << "A(j,i)=" << A(v(j), i) << " A(i,i) = " << A(v(i), i)
//		      << "\n";
	    for (int k = i; k < A.n; ++k) { // loop over columns
		A(v(j), k) =
		  modulo(A(v(j), k) * A(v(i), i) - A(v(i), k) * tmp, p);
	    }
	    // std::cout <<"A = \n";
	    // A.print();
	}
    }

    std::cout << "A = \n";
    A.print();

    // compute determinant
    int det = 1;
    for (int i = 0; i < A.m; ++i) {
	det = det * A(v(i), i);
    }
    std::cout << "pivot vector v = \n";
    v.print();

    Vector test(3);
    Vector rhs = vector_subset(A.n-1, A, 1);
    cout << "vector rhs = \n";
    rhs.print();
	// compute solution
    Matrix R = matrix_subset(A.m, A.m, A, StorageOrder::RowMajor);
    std::cout << "R = \n";
    R.print();

    Vector sol = modular_backward_substitution(R, p, rhs, v);
    std::cout << "sol: \n";
    sol.print();
    // compute modulo at the end
    return modulo(det, p);
}
