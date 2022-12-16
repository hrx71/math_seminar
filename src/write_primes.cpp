// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
#include "../include/vec.hpp"
#include <fstream>

using namespace std;
 
Vector SieveOfEratosthenes(size_t n)
{
    // Create a boolean array "prime[0..n]"which will
    // be false if i is Not a prime, else true.
    //bool prime[n + 1];
    bool *prime = new bool[n+1];
    for (size_t i = 0; i < n+1; ++i){
        prime[i] = true;
    }
    size_t nof_p = n-1;   

    for (size_t p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (size_t i = p * p; i <= n; i += p){
                if (prime[i] == true){ // additional condition to count number of primes;
                    prime[i] = false;
                    nof_p -= 1;
                }
            }
        }
    }

    // Save all prime numbers to vector
    Vector primes(nof_p);
    size_t i = 0;
    for (size_t p = 2; p <= n; p++){
        if (prime[p]){
            primes(i) = p;
            i += 1;
        }
    }

    string filename("../include/primes32bit.txt");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
        cout << "failed to open " << filename << '\n';
    } else {
        for (size_t i = nof_p-1; i >= nof_p-1000; --i){
            file_out << primes(i) << endl;
        }
        cout << "Done Writing!" << endl;
    }

    delete[] prime; 
    
    return primes;
}
/* 
int main()
{
    //size_t n = pow(2, 32);
    //size_t n = 3037000499;
    size_t n = 46330;
    //cout << "Prime numbers smaller than or equal to " << n << "\n";
    Vector primes = SieveOfEratosthenes(n);
    return 0;
}*/
