#include <iostream>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    // Check for numbers less than or equal to 1
    if (n <= 1) return false;
    
    // Check for numbers equal to 2 or 3
    if (n == 2 || n == 3) return true;
    
    // Check if the number is divisible by 2 or 3
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // Check for numbers where all digits are equal
    int lastDigit = n % 10;
    int temp = n / 10;
    while (temp > 0) {
        if (temp % 10 != lastDigit) break;
        temp /= 10;
    }
    if (temp == 0) return false;  // All digits are equal
    
    // Check for numbers where the first digit is 1, 3, 7, or 9
    if (n > 10) {
        int firstDigit = n;
        while (firstDigit >= 10) {
            firstDigit /= 10;
        }
        if (firstDigit != 1 && firstDigit != 3 && firstDigit != 7 && firstDigit != 9) return false;
    }
    
    // Regular primality check by testing divisibility with primes
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19}; // Add more primes as needed
    for (int prime : primes) {
        if (prime * prime > n) break; // No need to check primes greater than sqrt(n)
        if (n % prime == 0) return false; // Number is divisible by prime, hence not prime
    }
    
    return true;  // Number is prime
}

int main() {
    // Test cases
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
