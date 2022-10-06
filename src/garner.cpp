#include <funcs.hpp>
#include <iostream>
#include <vector>

// array int klasse
void integerCRA(int* m, int* u,std::vector<int> &gamma)
{
    int* mp = new int[3];
    const int maxsize = 2;
    for(std::size_t k=0; k<maxsize; ++k) 
    {
	mp[k] = 1;
	for(std::size_t i=0; i<k-1; ++i) 
	{
	   mp[k] *= m[i]; 
	}
	gamma[k] = multinverse(mp[k],m[k]);
    }
   // delete[] gamma;
    delete[] mp;
}

