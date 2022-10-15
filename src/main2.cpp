#include <cstddef>
#include <iostream>
#include "../include/funcs.hpp"
//#include "../include/matrix.hpp"
//#include "../include/vec.hpp"
#include "./euclExtended.cpp"
//#include "./garner.cpp"
#include "modularGauss.cpp"
#include "modulo.cpp"
#include <vector>


int
main()
{/*
    std::cout << "Testing multiinverse!";
    std::cout << std::endl;
    int inv = multinverse(3,17);
    std::cout << "Inverse is inv = " << inv;
    std::cout << std::endl;
    
    int* m = new int[3];
    int* u = new int[3];
    std::vector<int> gamma(3);

    m[0] = 99;
    m[1] = 97;
    m[2] = 95;
    
    u[0] = 49;
    u[1] = -21;
    u[2] = -30;
	    
    //integerCRA(m, u, gamma);

    for(size_t i=0; i<2; ++i) {
	std::cout << "gamma= " << gamma[i];
	std::cout << std::endl;
    }
    delete[] m;
    delete[] u;
    */
    
   
    std::cout << "Testing Matrix Class\n";
    Matrix A(3,4,StorageOrder::RowMajor);
    // A.init();
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
    A(2,3) = 34;
    std::cout << " A = \n";
    /*A(0,0) = 3;
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

