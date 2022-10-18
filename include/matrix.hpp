#include <cassert> /* needed for assert */
#include <cstddef> /* needed for std::size_t and std::ptrdiff_t */
#include <iostream>

enum class StorageOrder
{
    ColMajor,
    RowMajor
};

/**
 * @brief Brief description
 *
 */
struct Matrix
{
    int m; /* number of rows */
    int n; /* number of columns */
    std::ptrdiff_t incRow;
    std::ptrdiff_t incCol;
    int* data;

    Matrix(int m, int n, StorageOrder order)
      : m(m)
      , n(n)
      , incRow(order == StorageOrder::ColMajor ? 1 : n)
      , incCol(order == StorageOrder::RowMajor ? 1 : m)
      , data(new int[m * n])
    {
    }

    ~Matrix() { delete[] data; }
 /*   Matrix(const Matrix& A)
    {
	m = A.m;
	n = A.m;
	
    }*/

    const int&
    operator()(int i, int j) const
    {
	assert(i < m && j < n);
	return data[i * incRow + j * incCol];
    }

    int&
    operator()(int i, int j)
    {
	assert(i < m && j < n);
	return data[i * incRow + j * incCol];
    }

    void
    init()
    {
	for (int i = 0; i < m; ++i) {
	    for (int j = 0; j < n; ++j) {
		data[i * incRow + j * incCol] = j * m + i + 1;
	    }
	}
    }

    void
    print()
    {
	for (int i = 0; i < m; ++i) {
	    std::cout << "  ";
	    for (int j = 0; j < n; ++j) {
		std::cout << data[i * incRow + j * incCol] << "   ";
	    }
	    std::cout << "\n";
	}
    }
};
