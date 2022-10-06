#include <cstddef>
#include <iostream>
#include <funcs.hpp>
#include <vector>


int
main()
{
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
	    
    integerCRA(m, u, gamma);

    for(size_t i=0; i<2; ++i) {
	std::cout << "gamma= " << gamma[i];
	std::cout << std::endl;
    }
    delete[] m;
    delete[] u;

    return(0);
}

