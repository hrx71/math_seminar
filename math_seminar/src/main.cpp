#include <cstddef>
#include <funcs.hpp>
#include <iostream>

using namespace std;

int
main()
{
    
    switch (1) {
	case 1: {
	    size_t const size = 5;
	    int* m = new int[size + 1];
	    int* u = new int[size + 1];
	    int* d = new int[size + 1];
	    m[0] = 7;
	    m[1] = 11;
	    m[2] = 13;
	    m[3] = 17;
	    m[4] = 19;
	    m[size] = 1;
	    for (size_t i = 0; i < size; ++i) {
		m[size] *= m[i];
	    }

	    u[0] = 2;
	    u[1] = -5;
	    u[2] = -2;
	    u[3] = 5;
	    u[4] = 9;

	    d[0] = -2;
	    d[1] = 1;
	    d[2] = 4;
	    d[3] = -2;
	    d[4] = -8;

	    u[size] = integerCRA(m, u, size);
	    
	    cout << "Symmetric Representation " << endl;
	    
	    if (m[size] % 2 != 0) {
		m[size] = m[size]-1;
	    }

	    if (u[size] < m[size]/2) {
		if(u[size] > -m[size]/2) {
		    cout << "u = " << u[size] << endl;
		} else {
		    cout << "u = " << u[size] + m[size] + 1 << endl;
		}
	    } else {
		cout << "u = " << u[size] - m[size] - 1 << endl;
	    }
	    
	    d[size] = integerCRA(m, d, size);
	    
	    cout << "Symmetric Representation " << endl;
	    
	    if (d[size] < m[size]/2) {
		if(d[size] > -m[size]/2) {
		    cout << "d = " << d[size] << endl;
		} else {
		    cout << "d = " << d[size] + m[size] + 1 << endl;
		}
	    } else {
		cout << "d = " << d[size] - m[size] - 1 << endl;
	    }

	    delete[] m;
	    delete[] u;
	    delete[] d;
	    break;
	}
	case 2: {
	    size_t const size = 3;
	    int* m = new int[size + 1];
	    int* u = new int[size + 1];

	    m[0] = 99;
	    m[1] = 97;
	    m[2] = 95;
	    m[size] = 1;
	    for (size_t i = 0; i < size; ++i) {
		m[size] *= m[i];
	    }

	    u[0] = 49;
	    u[1] = -21;
	    u[2] = -30;

	    u[size] = integerCRA(m, u, size);
	    
	    if (m[size] % 2 != 0) {
		m[size] = m[size]-1;
	    }

	    if (u[size] < m[size]/2) {
		if(u[size] > -m[size]/2) {
		    cout << "u = " << u[size] << endl;
		} else {
		    cout << "u = " << u[size] + m[size] + 1 << endl;
		}
	    } else {
		cout << "u = " << u[size] - m[size] - 1 << endl;
	    }

	    delete[] m;
	    delete[] u;
	    break;
	}
	case 3: {
	    size_t const size = 3;
	    int* m = new int[size + 1];
	    int* u = new int[size + 1];

	    m[0] = 5;
	    m[1] = 7;
	    m[2] = 11;
	    m[size] = 1;
	    for (size_t i = 0; i < size; ++i) {
		m[size] *= m[i];
	    }
	    u[0] = 4;
	    u[1] = 1;
	    u[2] = 2;

	    u[size] = integerCRA(m, u, size);
	    
	    // Calculate symmetric representation
	    if (m[size] % 2 != 0) {
		m[size] = m[size]-1;
	    }

	    if (u[size] < m[size]/2) {
		if(u[size] > -m[size]/2) {
		    cout << "u = " << u[size] << endl;
		} else {
		    cout << "u = " << u[size] + m[size] + 1 << endl;
		}
	    } else {
		cout << "u = " << u[size] - m[size] - 1 << endl;
	    }
	    
	    delete[] m;
	    delete[] u;
	    break;
	}
    }
    
    cout<<"Testing Matrix Class\n";
    Matrix A(3,4,StorageOrder::RowMajor);

    cout<<"Initializing the Matrix:\n";
    int modop = 1;
    int mod = 13;
    init(A, mod, 0);
    A.print();
    cout <<"\n";
    
    if(modop) {
	cout<<"mod operation on Matrix:\n";
	init(A, mod, modop);
	A.print();
	cout <<"\n";
    }
    cout << "Testing Gauss determinant:\n";
    int det = modularGauss(A, mod);
    cout <<"\n";
    cout << "det = " << det << endl << endl;

    return (0);
}

