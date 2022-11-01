#include <cstddef>
#include <funcs.hpp>
/**
 * @brief Performs backward substitution considering modulo
 *
 * @param R right upper triangular matrix (rows might be permutated)
 * @param p prime number for modulo
 * @param rhs right hand side of the linear system of equations
 * @param pivot vector with row indexes (permutation)
 * @return Vector: solution
 */
Vector
modular_backward_substitution(Matrix& R,
			      const int p,
			      Vector& rhs,
			      Vector& pivot)
{
    assert(R.m == R.n); // R needs to be quadratic
    Vector sol(R.n + 1);

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

/**
 * @brief Matrix subsetting function
 *
 * needed for splitting matrix resulting from modular gauss implementation
 *
 * @param m1 number of rows of new matrix
 * @param n1 number of columns of new matrix
 * @param A Matrix to be subset
 * @param order storage order of the new matrix
 * @return Matrix subset
 */
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
/**
 * @brief Vector subsetting function
 *
 * needed for splitting matrix resulting from modular gauss implementation
 *
 * @param index row or column index of interest
 * @param A Matrix to subset vector from
 * @param col bool to specify if column or row should be subset
 * @return Vector subset
 */
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
 * @brief Gauss Elimination modulo an integer
 *
 * Transform to a right upper triangular matrix and solving of the system of
 * linear equations
 *
 * @param A matrix consisting of Coefficients and right hand side to be solved
 * @param p prime number
 * @return int determinant modulo p
 */
int
modular_gauss(Matrix& A, int p)
{
    // create vector v for pivot of size number of rows of A
    Vector v(A.m);
    v.init(); // fill list of the form {0, 1, 2, ..., m-1}

    int fdet = 1; // corrector for determinant when multiplying a row
    int sign = 1; // corrector for determinant when swapping rows

    for (int i = 0; i < A.m - 1; ++i) { // loop over rwos
	if (A(v(i), i) == 0) {
	    // find pivot element: find maximum absolute value in this column
	   // std::cout << "Pivot!\n";
	    sign *= -1; // correct
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
	    fdet *= A(v(i), i);
	    for (int k = i; k < A.n; ++k) { // loop over columns
		A(v(j), k) =
		  modulo(A(v(j), k) * A(v(i), i) - A(v(i), k) * tmp, p);
	    }
	}
    }
    //cout <<"gauss matrix"<<endl;
    //A.print();
    // compute determinant
    int det = 1;
    for (int i = 0; i < A.m; ++i) {
	det = det * A(v(i), i);
    }
    // correction of the determinant
    // source of this method:
    // https://stackoverflow.com/questions/12235110/modulo-of-division-of-two-numbers
    // cout << "mod(det) before = " << modulo(det,p) << "\n";
    // cout << "mod(fdet) = "<< modulo(fdet,p) << "\n";
    //
    /*cout<<"fdet="<<fdet<<endl;
    cout<<"p="<<p<<endl;
    cout<<"det="<<det<<endl;
    */
    int fdet_inv = multinverse(fdet, p);
    //cout<<"finished with multiinverse"<<endl;
    // cout << "inv(fdet) mod p= "<< fdet_inv << "\n";
    // cout << "sign = " << sign << "\n";
    det = modulo(det * fdet_inv * sign, p);
    // cout << "det atfer correction = " << det << "\n";

    return det;
}

Matrix
copy_matrix(Matrix& A)
{
    Matrix B(A.m, A.n, StorageOrder::RowMajor);
    for (int i = 0; i < A.m; ++i) {
	for (int j = 0; j < A.n; ++j) {
	    B(i, j) = A(i, j);
	}
    }
    return B;
}

Matrix
exchange_column(Matrix& A, Vector& rhs, const int index)
{
    assert(A.m == rhs.m);
    Matrix B = copy_matrix(A);

    for (int i = 0; i < A.m; ++i) {
	B(i, index) = rhs(i);
    }
    return B;
}

Matrix
modular_cramer(Matrix& A, Vector& rhs, const Vector& primes)
{
    assert(A.m == A.n);
    cout << "Cramer rule begins\n";
    Matrix coefficients(primes.m-1, A.m + 1, StorageOrder::RowMajor);
    for (int i = 0; i < primes.m-1; ++i) {
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	int p = primes(i);
	cout << "This is prime number p = " << p << "\n";
	A.print();
	Matrix Acopy1 = copy_matrix(A);
	    //Calculate the Matrix modulo
	    for (int i = 0; i < Acopy1 .m; ++i) {
		for (int j = 0; j < Acopy1.n; ++j) {
		    Acopy1(i, j) = modulo(Acopy1(i, j), p);
		}
	    }
	coefficients(i, A.m) = modular_gauss(Acopy1, p);
	Matrix Acopy = copy_matrix(A);
	// then compute determinant of modified matrices.
	for (int l = 0; l < A.m; ++l) {
	    Matrix B = exchange_column(Acopy, rhs, l);
	    //Calculate the Matrix modulo
	    for (int i = 0; i < B.m; ++i) {
		for (int j = 0; j < B.n; ++j) {
		    B(i, j) = modulo(B(i, j), p);
		}
	    }
	    coefficients(i, l) = modular_gauss(B, p);
	}
    }
    cout <<"coefficient matrix:"<<endl;
    cout <<"  "<< "x" <<"   "<<"y"<<"   "<<"z"<<"   "<<"d"<<endl;
    cout <<"___________________"<<endl;
    coefficients.print();
    return coefficients;
}

