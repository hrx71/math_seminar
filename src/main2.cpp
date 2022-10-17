#include <cstddef>
#include <iostream>
#include "../include/funcs.hpp"
//#include "../include/matrix.hpp"
//#include "../include/vec.hpp"
//#include "./euclExtended.cpp"
//#include "./garner.cpp"
#include "modularGauss.cpp"
#include <vector>


int
main()
{

    
   
    std::cout << "Testing Matrix Class\n";
    Matrix A(2,3,StorageOrder::RowMajor);
    // A.init();
    /*
    A(0,0) = 22;
    A(1,0) = 15;
    A(2,0) = -25;

    A(0,1) = 44;
    A(1,1) = 14;
    A(2,1) = -28;

    A(0,2) = 74;
    A(1,2) = -10;
    A(2,2) = 20;

    A(0,3) = 1;
    A(1,3) = -2;
    A(2,3) = 34;*/
    A(0,0) = 3;
    A(1,0) = 7;

    A(0,1) = 5;
    A(1,1) = 3;

    A(0,2) = 14;
    A(1,2) = 6;
    std::cout << " A = \n";
    /*
    A(0,0) = 3;
    A(1,0) = 1;
    A(2,0) =  4;
    A(3,0) = -1;

    A(0,1) = 4;
    A(1,1) = -1;
    A(2,1) = -3;
    A(3,1) = 1;

    A(0,2) = -2;
    A(1,2) = 2;
    A(2,2) = 4;
    A(3,2) = 6;

    A(0,3) = 1;
    A(1,3) = 2;
    A(2,3) = -3;
    A(3,3) = -1;

    A(0,4) = -2;
    A(1,4) = 7;
    A(2,4) = 2;
    A(3,4) = 1;*/
    A.print();

    std::cout << "Testing Gauss determinant:\n";
    int det = modularGauss(A, 17);
    std::cout << "det = " << det;
    
    return(0);
}

