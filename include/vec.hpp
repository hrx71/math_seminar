#include <cassert> /* needed for assert */
#include <iostream>

using namespace std;

/**
 * @brief Vector class
 * 
 * struct to store vectors of size_t, access and modify their values.
 */
struct Vector {
   const size_t m; /* number of rows */
   ptrdiff_t* data;

   Vector(size_t m) :
         m(m), 
         data(new ptrdiff_t[m]) {
   }

   ~Vector() {
      delete[] data;
   }

   // provide value (read data)
   const ptrdiff_t& operator()(size_t i) const {
      assert(i < m);
      return data[i];
   }

   // access value (write data)
   ptrdiff_t& operator()(size_t i) {
      assert(i < m);
      return data[i];
   }

   void init() {
      for (size_t i = 0; i < m; ++i) {
        data[i] = i;
      }
   }

   void print() {
      for (size_t i = 0; i < m; ++i) {
        std::cout << "  ";
        std::cout << data[i] << "   ";
        std::cout << "\n";
      }
   }
};

