#include <cassert> /* needed for assert */
#include <iostream>

/**
 * @brief Vector class
 * 
 * struct to store vectors of integers, access and modify their values.
 */
struct Vector {
   const int m; /* number of rows */
   int* data;

   Vector(int m) :
         m(m), 
         data(new int[m]) {
   }

   ~Vector() {
      delete[] data;
   }

   // provide value (read data)
   const int& operator()(int i) const {
      assert(i < m);
      return data[i];
   }

   // access value (write data)
   int& operator()(int i) {
      assert(i < m);
      return data[i];
   }

   void init() {
      for (int i = 0; i < m; ++i) {
        data[i] = i;
      }
   }

   void print() {
      for (int i = 0; i < m; ++i) {
        std::cout << "  ";
        std::cout << data[i] << "   ";
        std::cout << "\n";
      }
   }
};

