#include <iostream>
#include <fstream>
#include <string>
#include "../include/vec.hpp"

using namespace std;

/**
 * @brief Reads in file line by line and puts integers in a vector
 * 
 * @param filepath path to given file
 * @param nof_lines number of lines to read in
 * @return Vector vector with read-in prime numbers
 */

Vector read_primes(string filepath, int nof_lines) {

    Vector primes(nof_lines);
    std::ifstream input(filepath);

    for (int i = 0; i < nof_lines; ++i) {
        input >> primes(i);
    }
    return primes;
}

// Test of the function
int main(){
    Vector primes = read_primes("../include/primes.txt", 200);
    primes.print();
    return 0;
}