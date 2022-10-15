#include <iostream>

#include <utility>

  using namespace std;

/* return the gcd of a and b followed by the pair x and y of
 *
 *       equation ax + by = gcd(a,b)
 *
 *           */

pair<int, pair<int, int>>
extendedEuclid(int a, int b)

{

    int x = 1, y = 0;

    int xLast = 0, yLast = 1;

    int q, r, m, n;

    while (a != 0)

    {

	q = b / a;

	r = b % a;
	
/*	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	cout<<"q=" <<q<<endl;
	cout<<"b/a=" << b/a<<endl;
	cout<<"r=" << b%a<<endl;
*/
	m = xLast - q * x;

	n = yLast - q * y;

	xLast = x;

	yLast = y;

	x = m;

	y = n;

	b = a;

	a = r;
    }
//    cout<<"b="<<b<<endl;
    cout<<"xLast="<<xLast<<endl;
    cout<<"yLast="<<yLast<<endl;

    int k = make_pair(b, make_pair(xLast, yLast));
    cout<<"k ="<<k<<endl;
    return k;
}

int
modInverse(int a, int m)

{

//    cout<<"extendedEuclid(a, m).second.first"<<extendedEuclid(a, m).second.first<<endl;
    cout<<"m="<<m<<endl;
    return (extendedEuclid(a, m).second.first + m) % m;
}

//Main

int main()

{

    int a, m;

    cout<<"Enter number to find modular multiplicative inverse: ";

    cin>>a;

    cout<<"Enter Modular Value: ";

    cin>>m;

 cout<<modInverse(a, m)<<endl;
    
}
