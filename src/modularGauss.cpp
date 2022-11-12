#include <cstddef>
#include <funcs.hpp>

/**
 * @brief Gauss Elimination modulo a prime
 *
 * Transform to a right upper triangular matrix and computing the determinant
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

    // Calculate the Matrix modulo
    for (int i = 0; i < A.m; ++i) {
	for (int j = 0; j < A.n; ++j) {
	    A(i, j) = modulo(A(i, j), p);
	}
    }
   // cout << "Matrix modulo p: " << p << endl;
   // A.print();
    int fdet = 1; // corrector for determinant when multiplying a row
    int sign = 1; // corrector for determinant when swapping rows
    int det = 1;

    for (int i = 0; i < A.m - 1; ++i) { // loop over rwos
	if (A(v(i), i) == 0) {
	    // find pivot element: find maximum absolute value in this column
	    sign *= -1; // correction of determinant
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
	    if (!(A(v(i), i))) {
		return 0;
	    }
	    fdet *= A(v(i), i);
	    fdet = modulo(fdet, p);
	    for (int k = i; k < A.n; ++k) { // loop over columns
		A(v(j), k) =
		  modulo(A(v(j), k) * A(v(i), i) - A(v(i), k) * tmp, p);
	    }
//	    cout << endl;
//	    cout << "i=" << i << " "
//		 << "j=" << j << endl;
//	    A.print();
//	    cout << endl;
	}
    }
//    cout << "gauss matrix for p=:" << p << endl;
//    A.print();
    //  compute determinant
    for (int i = 0; i < A.m; ++i) {
	det = modulo(det * A(v(i), i),p);
    }
    // correction of the determinant
    // source of this method:
    // https://stackoverflow.com/questions/12235110/modulo-of-division-of-two-numbers
    //	cout<<"det ="<<det<<endl;
    // cout<<"p="<<p<<endl;
    
    int fdet_inv = multinverse(fdet, p); // compute inverse value to avoid dividing
    //cout<<"fdet_inv"<<fdet_inv<<endl;
    det = modulo(det * fdet_inv * sign, p);
    cout << "det for p= " << p << " det = " << det << endl;
    // cout<<"fdet_inv"<<fdet_inv<<endl;
    return det;
}

/**
 * @brief Copy a matrix
 *
 * @param A Matrix to be copied
 * @return Matrix
 */
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

/**
 * @brief Exchange the column of a Matrix for Cramers's rule
 *
 * @param A Matrix
 * @param rhs new column which should be exchanged
 * @param index index of the column
 * @return Matrix
 */
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

/**
 * @brief Performs cramer's rule to solve a LSE, performed module different
 * primes
 *
 * @param A Matrix
 * @param rhs right hand side
 * @param primes array of primes
 * @return Matrix
 */
Matrix
modular_cramer(Matrix& A, Vector& rhs, const Vector& primes)
{
    assert(A.m == A.n);
    cout << "Cramer rule begins\n";
    Matrix coefficients(A.m + 1, primes.m - 1, StorageOrder::RowMajor);
    for (int i = 0; i < primes.m - 1; ++i) {
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	int p = primes(i);
	cout << "This is prime number p = " << p << "\n";
	A.print();
	Matrix Acopy = copy_matrix(A);
	// Matrix Acopy1 = copy_matrix(A);

	coefficients(A.m, i) = modular_gauss(Acopy, p);
	// then compute determinant of modified matrices.
	for (int l = 0; l < A.m; ++l) {
	    Matrix B = exchange_column(A, rhs, l);
	    coefficients(l, i) = modular_gauss(B, p);
	}
    }
    cout << "coefficient matrix:" << endl;
    cout << "  "
	 << "x"
	 << "   "
	 << "y"
	 << "   "
	 << "z"
	 << "   "
	 << "d" << endl;
    cout << "___________________" << endl;
    coefficients.print();
    return coefficients;
}

/**
 * @brief Berechnet die Deterinanten einer Matrix modulo p
 *
 * @param A
 * @param primes
 * @return Vector
 */
Vector
modular_determinant(Matrix& A, const Vector& primes)
{
    assert(A.m == A.n);
    Vector coefficients(primes.m - 1);
    for (int i = 0; i < primes.m - 1; ++i) {
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	int p = primes(i);
	//		cout << "This is prime number p = " << p << "\n";
	//		A.print();
	Matrix Acopy = copy_matrix(A);
	// Matrix Acopy1 = copy_matrix(A);

	coefficients(i) = modular_gauss(Acopy, p);
    }
    /*	cout << "coefficient vector:" << endl;
	    coefficients.print();*/
    return coefficients;
}
