#include <cassert> /* needed for assert */
#include <iostream>

/**
 * @brief Vector class
 * 
 * struct to store vectors of integers, access and modify their values.
 */
struct Vector {
   const std::size_t m; /* number of rows */
   size_t* data;

   Vector(std::size_t m) :
         m(m), 
         data(new std::size_t[m]) {
   }

   ~Vector() {
      delete[] data;
   }

   // provide value (read data)
   const std::size_t& operator()(std::size_t i) const {
      assert(i < m);
      return data[i];
   }

   // access value (write data)
   std::size_t& operator()(std::size_t i) {
      assert(i < m);
      return data[i];
   }

   void init() {
      for (std::size_t i = 0; i < m; ++i) {
        data[i] = i;
      }
   }

   void print() {
      for (std::size_t i = 0; i < m; ++i) {
        std::cout << "  ";
        std::cout << data[i] << "   ";
        std::cout << "\n";
      }
   }
};

