#include <funcs.hpp>
#include <iostream>

using namespace std;

/**
 * @brief Implementation of Garner's alogorithm 
 * 
 * Chinese remainder alogrithm to solve congruence system
 * 
 * @param m array of intergers
 * @param u array of integers
 * @param size 
 * @return int 
 */
int
integerCRA(Vector& m,Vector& u)
{
    // Step 1- Compute the modular multiplicative inverse gamma[?]
    size_t size = m.m-1;
    Vector mp(size);
    Vector gamma(size);
    Vector v(size);
    
    for (size_t k = 0; k < size - 1; ++k) {
	mp(k) = m(0);
	for (size_t i = 1; i < k + 1; ++i) {
	    mp(k) *= m(i);
	}
	// do 99 % 97 --> 2 modular inverse is the same as 99 mod 97 kongruent 2
	// mod 97
	gamma(k) = multinverse(modulo(mp(k), m(k + 1)), m(k + 1));
/*	cout<<"k"<<k<<endl;
	cout<<"gamma(k)"<<gamma(k)<<endl;*/
    }

    // Step 2- Compute the radix coefficients
    v(0) = u(0);

    for (size_t k = 1; k < size; ++k) 
    {
	int tmp = v(k-1);
	for (ptrdiff_t j = k - 2; j > -1; --j) { 
	    tmp = tmp * m(j) + v(j);
	}
	// for the negativ representation
	v(k) = modulo((u(k) - tmp) * gamma(k-1), m(k));
//	v(k) = (u(k) - tmp) * gamma(k-1);
    }

    for (size_t i = 0; i < size; ++i) 
    {
	int vausgabe = v(i);
	cout << "v(i)= " << vausgabe;
	cout << std::endl;
    }
    // mixed radix representation
    u(size) = 0; 
    for (ptrdiff_t k=size-1; k>-1; --k) 
    {
//	cout<<"k = "<< k <<endl; 
//	cout<<" u[size] = "<<u(size) <<endl;
//	cout <<"v[k] ="<<v(k)<<endl;
	u(size) = u(size)*m(k) + v(k);	
    }
    return u(size); 

}

