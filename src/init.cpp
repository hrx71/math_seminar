#include <funcs.hpp>

/**
 * @brief Initialisation function for matrix struct
 * 
 * @param M Matrix to be initialised or overwritten
 * @param mod prime number if modular version is needed
 * @param modop bool if modulo should be applied to matrix
 */
void
init(Matrix& M, int mod, bool modop)
{
    std::cout << "Testing Matrix Class\n";
    /* M(0,0) = 3;
     M(1,0) = 7;

     M(0,1) = 5;
     M(1,1) = 3;

     M(0,2) = 14;
     M(1,2) = 6;
     std::cout << " M = \n";
   */

    /*
    M(0, 0) = 3;
    M(1, 0) = 1;
    M(2, 0) = 4;
    M(3, 0) = -1;

    M(0, 1) = 4;
    M(1, 1) = -1;
    M(2, 1) = -3;
    M(3, 1) = 1;

    M(0, 2) = -2;
    M(1, 2) = 2;
    M(2, 2) = 4;
    M(3, 2) = 6;

    M(0, 3) = 1;
    M(1, 3) = 2;
    M(2, 3) = -3;
    M(3, 3) = -1;

    M(0, 4) = -2;
    M(1, 4) = 7;
    M(2, 4) = 2;
    M(3, 4) = 1;
    */
    
	M(0, 0) = 22;
	M(1, 0) = 15;
	M(2, 0) = -25;

	M(0, 1) = 44;
	M(1, 1) = 14;
	M(2, 1) = -28;

	M(0, 2) = 74;
	M(1, 2) = -10;
	M(2, 2) = 20;

	M(0, 3) = 1;
	M(1, 3) = -2;
	M(2, 3) = 34;
      
    if (modop) {
	for (int i = 0; i < M.m; ++i) {
	    for (int j = 0; j < M.n; ++j) {
		M(i, j) = modulo(M(i, j), mod);
	    }
	}
    }
}
