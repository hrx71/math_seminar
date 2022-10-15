#include <cassert> /* needed for assert */
#include <cstddef> /* needed for std::size_t and std::ptrdiff_t */
#include <iostream>

enum class StorageOrder {ColMajor, RowMajor};

/**
 * @brief Brief description
 * 
 * 
 */
struct Matrix {
   const int m; /* number of rows */
   const int n; /* number of columns */
   const std::ptrdiff_t incRow;
   const std::ptrdiff_t incCol;
   int* data;

   Matrix(int m, int n, StorageOrder order) :
         m(m), n(n),
         incRow(order == StorageOrder::ColMajor? 1: n),
         incCol(order == StorageOrder::RowMajor? 1: m),
         data(new int[m*n]) {
   }

   ~Matrix() {
      delete[] data;
   }

   const int& operator()(int i, int j) const {
      assert(i < m && j < n);
      return data[i*incRow + j*incCol];
   }
   
   int& operator()(int i, int j) {
      assert(i < m && j < n);
      return data[i*incRow + j*incCol];
   }

   void init() {
      for (int i = 0; i < m; ++i) {
         for (int j = 0; j < n; ++j) {
            data[i*incRow + j*incCol] = j * m + i + 1;
         }
      }
   }

   void print() {
      for (int i = 0; i < m; ++i) {
         std::cout << "  ";
         for (int j = 0; j < n; ++j) {
            std::cout << data[i*incRow + j*incCol] << "   ";
         }
         std::cout << "\n";
      }
   }
};
