#include <cstddef>
#include <iostream>
#include <funcs.hpp>
#include <vector>

using namespace std;

int
main()
{
    cout << "Testing multiinverse!";
    cout << std::endl;
    int inv = multinverse(346,95);
    cout << "Inverse is inv = " << inv;
    cout << std::endl;
    
    size_t  const size = 3;
    int* m = new int[size];
    int* u = new int[size];

    m[0] = 99;
    m[1] = 97;
    m[2] = 95;
    
    u[0] = 49;
    u[1] = -21;
    u[2] = -30;
	    
    integerCRA(m, u, size);

    delete[] m;
    delete[] u;

    return(0);
}

