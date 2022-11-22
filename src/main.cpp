#include <fstream>
#include <funcs.hpp>
#include <iostream>
#include <string>
#include <cstddef>
//#include <unistd.h>
//#include <walltime.hpp>

using namespace std;

int
main()
{
    // TESTING//
    //time_dat time_eval;
    //WallTime<double> timer;
    std::string base = "../data/matrix1.txt";
    // cout<<base<<endl;
    for (int r = 6; r < 7; ++r) {
	// Read Matrix
	std::string s = std::to_string(r);
	base.replace(14, 1, s);
	//timer.tic();
	Matrix M = read_matrix_from_file(base);
	//time_eval.time_matrix = timer.toc();

	//M.print();
	// Read rhs
	//timer.tic();
	Vector rhs = read_vector_from_file("../data/rhs.txt", M.m);
	//time_eval.time_vector = timer.toc();

	Vector testcases(14);
	testcases(0) = 13;
	testcases(1) = 14;
	testcases(2) = 15;
	testcases(3) = 16;
	testcases(4) = 17;
	testcases(5) = 18;
	testcases(6) = 19;
	testcases(7) = 20;
	testcases(8) = 21;
	testcases(9) = 22;
	testcases(10) = 28;
	testcases(11) = 29;
	testcases(12) = 30;
	testcases(13) = 31;

	// Read primes in
//	Vector primes = read_vector_from_file("../data/primes_small.txt", 7);
	//Vector primes_big = read_vector_from_file("../include/primes32bit.txt", 100);

	Vector primes_big = read_vector_from_file("../include/primes32bit.txt", 100);
	//std::string base_time = "../data/time1.dat";
	//base_time.replace(12, 1, s);
	//cout << base_time << endl;
	//ofstream fout(base_time);

	for (int i = 0; i < 14; ++i) {
	    int size = testcases(i) + 1;

	    Vector p(size);
	    for (int j = 0; j < size - 1; ++j) {
		p(j) = primes_big(j);
	    }

	    mpz_t prodprim;

	    mpz_init_set_ui(prodprim, 1);

	    p(size - 1) = 1;
	    for (int i = 0; i < size - 1; ++i) {
		mpz_mul_ui(prodprim, prodprim, p(i));
		p(size - 1) *= p(i);
	    }
	    cout << "-----------------------------------------" << endl;
	    cout << endl << "testcase(" << i << "):" << endl;
	    cout << "Matrix dimension: " << M.m << "x" << M.n << endl;
	    cout << endl
		 << "Used prime numbers, last one is the product" << endl;
	    p.print();
	    cout << endl;
	    cout <<"prodprim:"<<endl;
	    mpz_out_str(stdout, 10, prodprim);
	    cout <<endl;
	    cout << "Anwendung als Determinantenbrechnung" << endl;
	    bool questionregular = 0;

	    //timer.tic();
	    Vector det_congruence_system = modular_determinant(M, p, questionregular);
	    //time_eval.time_modgauss = timer.toc();
	    if(!questionregular) {
	    int d = integerCRA(p, det_congruence_system);
	    //time_eval.time_garner = timer.toc() - time_eval.time_modgauss;

	    d = to_symmetric(d, p(size - 1));
	    //time_eval.time_comp = timer.toc();
	    cout << endl << "determinant: " << d << endl;

	    //--Working with gnu-gmp
	    //
	    mpz_t result;
	    mpz_init(result);

	    //timer.tic();
	    integerCRA_mp(result, p, det_congruence_system);
	    //time_eval.time_garner_gmp = timer.toc();

	    cout << "determinant_gmp= ";
	    to_symmetric_mp(result, prodprim);
	    mpz_out_str(stdout, 10, result);
	    cout << endl;

	    // Clear all mpz types
	    mpz_clear(result);
	    mpz_clear(prodprim);

	    // Writing time to file
	    /*cout << endl << "Writing to file started" << endl;
	    fout << time_eval.time_matrix << ' ' << time_eval.time_vector << ' '
		 << time_eval.time_modgauss << ' ' << time_eval.time_garner
		 << ' ' << time_eval.time_garner_gmp << ' '
		 << time_eval.time_comp << endl;
	    fout << endl;
	    cout << "Writing to file finished" << endl;*/
	}
	//fout.close();
    }
    }
    return (0);
}
// TODO:
/*

Irgendwannn:
* Verbesserungen wie verfrühte Abbruchbedingungen
* Main Funktion: user input integrieren, Eingabe von Speicherpfad(en) und ob
Determinante oder LGS-Lsöung nötig

Polina:
* Bigint-Library finden, nötig (siehe Koc. S. 3 - multiprecision integers)
* Bigint miteinbinden für die Speicherung der Coeffizienten für die
Cramer-Berechnung
* neue Funktion zur Anwendung der Determinantenberechnung

Jonas:
* Testen was bei großen Primzahlen passiert (Laufzeitanalyse)
* n=100, 200, ..., 1000
* Einbinden der Primzahlliste


* Hadermard oder Abbruchbedingen mit der adjungierten implementieren
*/
