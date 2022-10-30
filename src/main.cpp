//#include <funcs.hpp>
#include "../include/funcs.hpp"
#include <iostream>

using namespace std;

int main()
{	
	Matrix M(3,3, StorageOrder::ColMajor);
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

	Vector p(5);
	p(0) = 7;
	p(1) = 11;
	p(2) = 13;
	p(3) = 17;
	p(4) = 19;

	M.print();
	rhs.print();
	p.print();

	Matrix Coeffs = modular_cramer(M, rhs, p);
	Coeffs.print();
	return (0);
}
