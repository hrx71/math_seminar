#include <cstddef>
#include <iostream>
//#include "../include/matrix.hpp"
//#include "../include/vec.hpp"
#include <vector>

/**
 * @brief Perfoming Gauss Elimination modulo an integer and computing determinant
 * 
 * @param A Matrix
 * @param p prime number 
 * @return int determinant modulo p
 */
int modularGauss(Matrix& A, const int p){
    // create vector v for pivot of size number of rows of A
    Vector v(A.m);
    v.init(); // fill with list of the frm {0, 1, 2, ..., m-1}

    for (int i = 0; i < A.m; ++i){
        for (int j = 0; j < A.m; ++j){
            A(i,j) = modulo_sym(A(i,j),p);
        }
    }
    A.print();

    for (int i = 0; i < A.m-1; ++i){ // loop over rwos
        if (A(v(i),i) == 0){
            // find pivot element: find maximum absolute value in this column
            std::cout << "Pivot!\n";
            int maxabs = 0;
            int maxptr = 0;
            for (int j = i; j < A.m; ++j){
                if (abs(A(v(j), i)) > maxabs){
                    maxabs = A(v(j),i);
                    maxptr = j;
                }
            }
            // swap pivot vector
            int tmp = v(i);
            v(i) = v(maxptr);
            v(maxptr) = tmp;
        }

        // gauss elimination
        for (int j = i+1; j < A.m; ++j){ //loop over lower rows
            int tmp=A(v(j),i);
            std::cout << "A(j,i)=" << A(v(j),i) << " A(i,i) = "<< A(v(i),i) <<"\n" ;
            for (int k = i; k < A.n; ++k){ //loop over columns
                A(v(j),k) =  modulo_sym(A(v(j),k)*A(v(i),i) - A(v(i),k)*tmp, p);
            }
            //std::cout <<"A = \n";
            //A.print();
        }
    }

    std::cout <<"A = \n";
    A.print();

    // compute determinant
    int det = 1;
    for (int i = 0; i < A.m; ++i){
        det = det*A(v(i),i);
    }
    std::cout << "pivot vector v = \n" ;
    v.print();
    
    // compute modulo at the end
    return modulo_sym(det,p);
}