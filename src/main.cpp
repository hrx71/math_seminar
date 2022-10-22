#include <funcs.hpp>
#include <iostream>

using namespace std;

int
main()
{
    /*
	 switch (1) {
	     case 1: {
		 size_t const size = 5;
		 Vector m(size + 1);
		 Vector u(size + 1);
		 Vector d(size + 1);
		 m(0) = 7;
		 m(1) = 11;
		 m(2) = 13;
		 m(3) = 17;
		 m(4) = 19;
		 m(size) = 1;
		 for (size_t i = 0; i < size; ++i) {
		     m(size) *= m(i);
		 }

		 u(0) = 2;
		 u(1) = -5;
		 u(2) = -2;
		 u(3) = 5;
		 u(4) = 9;

		 d(0) = -2;
		 d(1) = 1;
		 d(2) = 4;
		 d(3) = -2;
		 d(4) = -8;

		 u(size) = integerCRA(m, u);
		 cout<<"u(size)"<< u(size) <<endl;
		 cout << "Symmetric Representation " << endl;

		 if (m(size) % 2 != 0) {
		     m(size) = m(size) - 1;
		 }

		 if (u(size) < m(size) / 2) {
		     if (u(size) > -m(size) / 2) {
			 int solution =   u(size);
			 cout << "u = " << solution  << endl;
		     } else {
			 int solution =   u(size) + m(size) + 1;
			 cout << "u = " << solution << endl;
		     }
		 } else {
		 int solution =   u(size)-m(size) - 1;
		 cout << "u = " << solution<< endl;
		 }

		 d(size) = integerCRA(m, d);

		 cout << "Symmetric Representation " << endl;

		 if (d(size) < m(size) / 2) {
		     if (d(size) > -m(size) / 2) {
			 int solution = d(size);
			 cout << "d = " << solution << endl;
		     } else {
			 int solution = d(size)+m(size)+1;
			 cout << "d = " << solution << endl;
		     }
		 } else {
		     int solution = d(size)-m(size) - 1;
		     cout << "d = " << solution << endl;
		 }

		 break;
	     }
	 }*/
    /*	    case 2: {
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
			m[size] = m[size] - 1;
		    }

		    if (u[size] < m[size] / 2) {
			if (u[size] > -m[size] / 2) {
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
			m[size] = m[size] - 1;
		    }

		    if (u[size] < m[size] / 2) {
			if (u[size] > -m[size] / 2) {
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
	    }*/

    int size =4; //+1 to size of modulo
    Matrix A(4, 5, StorageOrder::RowMajor);
    Matrix M(A.n, size, StorageOrder::ColMajor);
    //    Vector sol(4);
    cout << "Initializing the Matrix:\n";
    int modop = 1;
    Vector mod(size + 1);
    //mod(0) = 997;
    mod(0) = 7;
    mod(1) = 11;
    mod(2) = 13;
    mod(3) = 17;
    //mod(4) = 19;
    //mod(5) = 23;
    //mod(6) = 29;
    //mod(7) = 31;
    /*mod(8) = 37;
    mod(9) = 41;
    mod(10) = 43;*/
   // mod(6) = 29;
    mod(size) = 1;
    for (int i = 0; i < size; ++i) {
	mod(size) *= mod(i);
    }
    
    cout<<mod(size)<<endl;
    
    init(A, mod(0), 0);
    A.print();
    cout << "\n";

    for (int i = 0; i < size; ++i) {

	if (modop) {
	    cout << "mod operation on Matrix:\n";
	    cout << "mod = " << mod(i) << "\n";
	    init(A, mod(i), modop);
	    A.print();
	    cout << "\n";
	}

	Vector sol = modularGauss(A, mod(i));
	
	cout<<endl<<"Gauss solution:"<<endl;
	for(size_t i=0; i<sol.m; ++i) {
	    cout<<"sol(i) = "<<sol(i)<<endl;
	}
	for (size_t k = 0; k < sol.m; ++k) {
	    M(k, i) = sol(k);
	}
    }
    cout << endl;
    cout << "Solution for the examples\n";
    M.print();

    Vector u(M.m);
    Vector rowM(size + 1);
    for (int i = 0; i < M.m; ++i) {
	for (int j = 0; j < M.n; ++j) {
	    rowM(j) = M(i, j);
	}

	u(i) = integerCRA(mod, rowM);

    }
    
    //Ausgabe
    cout <<"solution in unsymmetric view: "<<endl;
    for(int i=0; i< M.m; ++i) {
        cout<<"u(i)="<<u(i)<<endl;
    }
    cout <<"solution in symmetric view: "<<endl;
    for(int i=0; i< M.m; ++i) {
	
	if (mod(size) % 2 != 0) {
	    mod(size) = mod(size) - 1;
	}

	if (u(i) < mod(size) / 2) {
	    if (u(i) > -mod(size) / 2) {
		int solution = u(i);
		cout << "u = " << solution << endl;
	    } else {
		int solution = u(i) + mod(size) + 1;
		cout << "u = " << solution << endl;
	    }
	} else {
	    int solution = u(i) - mod(size) - 1;
	    cout << "u = " << solution << endl;
	}
    }
    /*cout <<"solution: "<<endl;
    u.print();*/
    cout<<"Final solution"<<endl;
    
    float x1=  (float) u(0)/ (float) u(u.m-1);
    float x2=  (float) u(1)/ (float) u(u.m-1);
    float x3=  (float) u(2)/ (float) u(u.m-1);
    float x4=  (float) u(3)/ (float) u(u.m-1);
    cout<<"x1="<<x1<<endl; 
    cout<<"x2="<<x2<<endl; 
    cout<<"x3="<<x3<<endl; 
    cout<<"x4="<<x4<<endl; 
    
    cout << endl;
    return (0);
}

