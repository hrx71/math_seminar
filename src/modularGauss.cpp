#include <cstddef>
//#include <funcs.hpp>
using namespace std;

/**
 * @brief Gauss Elimination modulo a prime
 *
 * Transform to a right upper triangular matrix and computing the determinant
 *
 * @param A matrix consisting of Coefficients and right hand side to be solved
 * @param p prime number
 * @return size_t determinant modulo p
 */
ptrdiff_t
modular_gauss(Matrix& A, size_t p)
{
    // create vector v for pivot of size number of rows of A
    Vector v(A.m);
    v.init(); // fill list of the form {0, 1, 2, ..., m-1}

    // Calculate the Matrix modulo
    for (size_t i = 0; i < A.m; ++i) {
		for (size_t j = 0; j < A.n; ++j) {
			A(i, j) = modulo(A(i, j), p);
		}
    }
   // cout << "Matrix modulo p: " << p << endl;
   // A.print();
    ptrdiff_t fdet = 1; // corrector for determinant when multiplying a row
    int sign = 1; // corrector for determinant when swapping rows
    ptrdiff_t det = 1;

    for (size_t i = 0; i < A.m - 1; ++i) { // loop over rwos
	if (A(v(i), i) == 0) {
	    // find pivot element: find maximum absolute value in this column
	    sign *= -1; // correction of determinant
	    ptrdiff_t maxabs = 0;
	    size_t maxptr = 0;
	    for (size_t j = i; j < A.m; ++j) {
		if (abs(A(v(j), i)) > maxabs) {
		    maxabs = A(v(j), i);
		    maxptr = j;
		}
	    }
	    // swap pivot vector
	    size_t tmp = v(i);
	    v(i) = v(maxptr);
	    v(maxptr) = tmp;
	}

	// gauss elimination
	for (size_t j = i + 1; j < A.m; ++j) { // loop over lower rows
	    ptrdiff_t tmp = A(v(j), i);
	    if (!(A(v(i), i))) {
		return 0;
	    }
	    fdet *= A(v(i), i);
	    fdet = modulo(fdet, p);
	    for (size_t k = i; k < A.n; ++k) { // loop over columns
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
    for (size_t i = 0; i < A.m; ++i) {
	det = modulo(det * A(v(i), i),p);
    }
    // correction of the determinant
    // source of this method:
    // https://stackoverflow.com/questions/12235110/modulo-of-division-of-two-numbers
    //	cout<<"det ="<<det<<endl;
    // cout<<"p="<<p<<endl;
    
    size_t fdet_inv = multinverse(fdet, p); // compute inverse value to avoid dividing
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
    for (size_t i = 0; i < A.m; ++i) {
	for (size_t j = 0; j < A.n; ++j) {
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
exchange_column(Matrix& A, Vector& rhs, const size_t index)
{
    assert(A.m == rhs.m);
    Matrix B = copy_matrix(A);

    for (size_t i = 0; i < A.m; ++i) {
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
    for (size_t i = 0; i < primes.m - 1; ++i) {
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	size_t p = primes(i);
	cout << "This is prime number p = " << p << "\n";
	A.print();
	Matrix Acopy = copy_matrix(A);
	// Matrix Acopy1 = copy_matrix(A);

	coefficients(A.m, i) = modular_gauss(Acopy, p);
	// then compute determinant of modified matrices.
	for (size_t l = 0; l < A.m; ++l) {
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
modular_determinant(Matrix& A, const Vector& primes, bool questionisregular)
{
    assert(A.m == A.n);
    Vector coefficients(primes.m - 1);
    for (size_t i = 0; i < primes.m - 1; ++i) {
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	size_t p = primes(i);
	//		cout << "This is prime number p = " << p << "\n";
	//		A.print();
	Matrix Acopy = copy_matrix(A);
	// Matrix Acopy1 = copy_matrix(A);


	coefficients(i) = modular_gauss(Acopy, p);
	if(questionisregular) {
	    if(coefficients(i) !=0) {
		cout << "Matrix is regular!"<<endl;
		return 0;
	    }
	}
    }
    /*	cout << "coefficient vector:" << endl;
	    coefficients.print();*/
    if(questionisregular) {
	cout<< "Matrix is singular!"<<endl;
    }
    return coefficients;
}


/*Vector
modular_determinant_thread(Matrix &A, const Vector &primes, bool questionisregular)
{
	assert(A.m == A.n);
	Vector coefficients(primes.m - 1);

	// get number of possible threads
	int nof_threads = thread::hardware_concurrency();
	vector<thread> threads(nof_threads);
	// create vector of threads
	// vector<thread> threads(nof_threads);
	cout << primes.m << endl;

	for (size_t i = 0; i < primes.m - 1; i = i + nof_threads)
	{
		cout << i << endl;
		
		int limit;
		if ((i + 1) * nof_threads > primes.m)
		{
			limit = primes.m - nof_threads * i;
		}
		else
		{
			limit = nof_threads;
		}
		for (int index = 0; index < limit; ++index)
		{
			size_t p = primes(i + index);
			threads[index] = std::thread([index, i, p]()
										 { cout << "This thread uses prime number with index " << i << "! working on p = " << p << "\n"; });
		}
		
		// first nof_threads coefficients available
		// 
	}
	for (auto &t : threads)
		{
			if (t.joinable())
				t.join();
		}
	
	// compute determinants with modular Gauss and p(i) as prime number
	// first, compute d
	size_t p = primes(i);
	//		cout << "This is prime number p = " << p << "\n";
	//		A.print();
	Matrix Acopy = copy_matrix(A);
	// Matrix Acopy1 = copy_matrix(A);

	coefficients(i) = modular_gauss(Acopy, p);
	if (questionisregular)
	{
		if (coefficients(i) != 0)
		{
			cout << "Matrix is regular!" << endl;
			return 0;
		}
	}
if (questionisregular)
{
	cout << "Matrix is singular!" << endl;
}

	// join threads

	return coefficients;
}
*/