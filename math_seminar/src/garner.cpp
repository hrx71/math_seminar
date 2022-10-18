#include <funcs.hpp>
#include <iostream>
#include <vector>

using namespace std;

// array int klasse
int
integerCRA(int* m, int* u, size_t const size)
{
    // Step 1- Compute the modular multiplicative inverse gamma[?]
    int* mp = new int[size];
    int* gamma = new int[size];
    int* v = new int[size];

    for (size_t k = 0; k < size - 1; ++k) {
	mp[k] = m[0];
	for (size_t i = 1; i < k + 1; ++i) {
	    mp[k] *= m[i];
	}
	// do 99 % 97 --> 2 modular inverse is the same as 99 mod 97 kongruent 2
	// mod 97
	gamma[k] = multinverse(modulo(mp[k], m[k + 1]), m[k + 1]);
    }

    // Step 2- Compute the radix coefficients
    v[0] = u[0];

    for (size_t k = 1; k < size; ++k) 
    {
	int tmp = v[k-1];
	for (ptrdiff_t j = k - 2; j > -1; --j) { 
	    tmp = tmp * m[j] + v[j];
	}
	// for the negativ representation
	v[k] = modulo((u[k] - tmp) * gamma[k-1], m[k]);
    }

    for (size_t i = 0; i < size; ++i) 
    {
	cout << "v[i]= " << v[i];
	cout << std::endl;
    }
    // mixed radix representation
    u[size] = v[size];
    for (ptrdiff_t k=size-1; k>-1; --k) 
    {
	u[size] = u[size]*m[k] + v[k];	
    }
    return u[size]; 

    delete[] gamma;
    delete[] mp;
}

