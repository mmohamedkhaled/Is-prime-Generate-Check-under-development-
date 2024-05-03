#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> generatePrimes(int limit) {
    vector<bool> sieve(limit + 1, true);
    vector<int> primes;

    for (int p = 2; p * p <= limit; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i <= limit; i += p) {
                sieve[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p) {
        if (sieve[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

// Function to check if a number is prime
bool isPrime(int n) {
    // Check for numbers less than or equal to 1
    if (n <= 1) return false;

    // Generate primes up to the square root of n
    int limit = sqrt(n);
    vector<int> primes = generatePrimes(limit);

    // Check if n is divisible by any prime less than or equal to the square root of n
    for (int prime : primes) {
        if (n % prime == 0) return false;
    }

    return true;
}

int main() {
    int numbers[] = {11, 21, 31, 41, 51, 13, 23, 33, 43, 53, 17, 27, 37, 47, 57, 19, 29, 39, 49, 59, 22, 111, 131};
    
    for (int num : numbers) {
        if (isPrime(num)) {
            cout << num << " is prime." << endl;
        } else {
            cout << num << " is composite." << endl;
        }
    }
    
    return 0;
}
