//#include <funcs.hpp>
#include "../include/funcs.hpp"
#include <iostream>

using namespace std;

int
main()
{
    int size = 6;
    Matrix M(3, 3, StorageOrder::ColMajor);
    Vector u(size-2);
    Vector colC(size);
    M(0, 0) = 22;
    M(1, 0) = 15;
    M(2, 0) = -25;

    M(0, 1) = 44;
    M(1, 1) = 14;
    M(2, 1) = -28;

    M(0, 2) = 74;
    M(1, 2) = -10;
    M(2, 2) = 20;

    Vector rhs(3);
    rhs(0) = 1;
    rhs(1) = -2;
    rhs(2) = 34;

    Vector p(size);
    p(0) = 7;
    p(1) = 11;
    p(2) = 13;
    p(3) = 17;
    p(4) = 19;
    
    p(size-1) = 1;
    for (int i = 0; i < size-1; ++i) {
	p(size-1) *= p(i);
    }

    M.print();
    rhs.print();
    p.print();

    Matrix Coeffs = modular_cramer(M, rhs, p);

    for (int j = 0; j < Coeffs.n; ++j) {
	for (int i = 0; i < Coeffs.m; ++i) {
	    colC(i) = Coeffs(i, j);
	}
	u(j) = integerCRA(p, colC);
    }
    
    for (int i = 0; i < u.m; ++i) {
    int half = p(size-1)/2;
	if (u(i) < half) {
	    if (u(i) < -half) {
		u(i) = u(i) + p(size-1) + 1;

	    }
	} else {
	    u(i) = u(i) - p(size-1) - 1;
	}
    }
    u.print();
    
    cout <<"integer representation:" <<endl;
    float x = (float) u(0)/(float)u(3);
    float y = (float) u(1)/(float)u(3);
    float z = (float) u(2)/(float)u(3);
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    cout<<"z="<<z<<endl;
  
    return (0);
}
