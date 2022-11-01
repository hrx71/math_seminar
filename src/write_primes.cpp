// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
// sources: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
// https://www.delftstack.com/de/howto/cpp/cpp-write-to-file/
#include <bits/stdc++.h>
#include "../include/vec.hpp"
#include <fstream>

using namespace std;
 
Vector SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]"which will
    // be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); //initalize all entries with true
    int nof_p = n-1;
 
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p){
                if (prime[i] == true){ // additional condition to count number of primes;
                    prime[i] = false;
                    nof_p -= 1;
                }
            }
        }
    }

    // Save all prime numbers to vector
    Vector primes(nof_p);
    int i = 0;
    for (int p = 2; p <= n; p++){
        if (prime[p]){
            primes(i) = p;
            i += 1;
        }
    }


    // write last 200 prime numbers in a file    
    // file will be overwritten
    string filename("../include/primes.txt");
    fstream file_out;

    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
        cout << "failed to open " << filename << '\n';
    } else {
        for (int i = nof_p-1; i >= nof_p-200; --i){
            file_out << primes(i) << endl;
        }
        cout << "Done Writing!" << endl;
    }
    
    return primes;
}
/* 
int main()
{
    int n = pow(2, 16);
    cout << "Prime numbers smaller than or equal to " << n << "\n";
    Vector primes = SieveOfEratosthenes(n);
    return 0;
    *
    * */
//}
