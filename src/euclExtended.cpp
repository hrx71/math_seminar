#include <numeric>
#include <iostream>
int 
multinverse(int a, int b) 
{
    if (std::gcd(a,b) != 1) {
	std::cout << "a is not invertible";
	std::cout <<std::endl;
    }
    
    if (b>a) 
    {
	int tmp=a;
	a = b;
	b = tmp;
    }
    
    int t = 0;
    int tt = 1;
    int r;
    int q;
    int T;

    while (b != 0) 
    {
	r = a % b;
	q = (a-r)/b;
	T = t-tt*q;
    // Reordering
	a = b;
	b = r;
	t = tt;
	tt = T;
    }
    return t;
}
