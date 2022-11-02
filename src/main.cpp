#include "../include/funcs.hpp"
#include <iostream>
using namespace std;

int main()
{
    Matrix M = read_matrix_from_file("../data/matrix1.txt");
    //Matrix N = read_matrix_from_file("../data/matrix2.txt");
    //N.print();
    M.print();

    Vector rhs = read_vector_from_file("../data/rhs.txt", M.m);
    rhs.print();

    // Vector primes = read_vector_from_file("../data/primes.txt", 20);
    // primes.print();
    int size = 6;

    Vector u(size - 2);
    Vector row_coefficient(size-1);

    Vector p(size);
    p(0) = 7;
    p(1) = 11;
    p(2) = 13;
    p(3) = 17;
    p(4) = 19;

    // add product of all primes
    p(size - 1) = 1;
    for (int i = 0; i < size - 1; ++i)
    {
        p(size - 1) *= p(i);
    }

    M.print();
    rhs.print();
    p.print();

    Matrix Coeffs = modular_cramer(M, rhs, p);

    // call chinese remainder theorem
    for (int i = 0; i < Coeffs.m; ++i)
    {
        for (int j = 0; j < Coeffs.n; ++j)
        {
            row_coefficient(j) = Coeffs(i, j);
        }
        u(i) = integerCRA(p, row_coefficient);
    }

    // convert to symmetric representation
    for (int i = 0; i < u.m; ++i){
        u(i) = to_symmetric(u(i), p(size-1));
    }
    u.print();

    cout << "integer representation:" << endl;
    float x = (float)u(0) / (float)u(3);
    float y = (float)u(1) / (float)u(3);
    float z = (float)u(2) / (float)u(3);
    cout << "x=" << x << endl;
    cout << "y=" << y << endl;
    cout << "z=" << z << endl;

    cout << "Anwednung als Determinantenbrechnung";
    Vector det_congruence_system = modular_determinant(M, p);
    int d = integerCRA(p, det_congruence_system);
    d = to_symmetric(d, p(size-1));
    cout << "determinant: " << d << endl;

    return (0);
}

// TODO:
/*

Irgendwannn: 
* Verbesserungen wie verfrühte Abbruchbedingungen
* Main Funktion: user input integrieren, Eingabe von Speicherpfad(en) und ob Determinante oder LGS-Lsöung nötig

Polina: 
* Bigint-Library finden, nötig (siehe Koc. S. 3 - multiprecision integers)
* Bigint miteinbinden für die Speicherung der Coeffizienten für die Cramer-Berechnung
* neue Funktion zur Anwendung der Determinantenberechnung

Jonas:
* Testen was bei großen Primzahlen passiert (Laufzeitanalyse)
* n=100, 200, ..., 1000
* Einbinden der Primzahlliste


* Hadermard oder Abbruchbedingen mit der adjungierten implementieren
*/
