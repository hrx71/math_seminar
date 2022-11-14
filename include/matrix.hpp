#include <cassert> /* needed for assert */
#include <iostream>

enum class StorageOrder
{
    ColMajor,
    RowMajor
};

using namespace std;
/**
 * @brief Matrix class
 *
 * Struct to store matrices of size_tegers, access and modify their values.
 */
struct Matrix
{
    size_t m; /* number of rows */
    size_t n; /* number of columns */
    std::ptrdiff_t incRow;
    std::ptrdiff_t incCol;
    ptrdiff_t *data;

    Matrix(size_t m, size_t n, StorageOrder order)
        : m(m), n(n), incRow(order == StorageOrder::ColMajor ? 1 : n), incCol(order == StorageOrder::RowMajor ? 1 : m), data(new ptrdiff_t[m * n])
    {
    }

    ~Matrix() { delete[] data; }
    /*   Matrix(const Matrix& A)
       {
       m = A.m;
       n = A.m;

       }*/

    // provide value (read data)
    const ptrdiff_t &
    operator()(size_t i, size_t j) const
    {
        assert(i < m && j < n);
        return data[i * incRow + j * incCol];
    }

    // access value (write data)
 ptrdiff_t &
    operator()(size_t i, size_t j)
    {
        assert(i < m && j < n);
        return data[i * incRow + j * incCol];
    }

    void
    init()
    {
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                data[i * incRow + j * incCol] = j * m + i + 1;
            }
        }
    }

    void
    print()
    {
        for (size_t i = 0; i < m; ++i)
        {
            std::cout << "  ";
            for (size_t j = 0; j < n; ++j)
            {
                std::cout << data[i * incRow + j * incCol] << "   ";
            }
            std::cout << "\n";
        }
    }
    Matrix(Matrix &P){
        m = P.m; 
        n = P.n; 
        incRow = P.incRow;
        incCol = P.incCol;
        data = new ptrdiff_t;
        *data = *P.data;
    }
};
