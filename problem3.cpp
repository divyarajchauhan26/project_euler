#include <bits/stdc++.h>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long maxFactor = -1;
    // remove factor 2
    while (n % 2 == 0) {
        maxFactor = 2;
        n /= 2;
    }
    // check odd factors
    for (long long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            maxFactor = i;
            n /= i;
        }
    }
    // if remainder > 1, it's a prime and the largest factor
    if (n > 1) maxFactor = n;
    return maxFactor;
}

int main() {
    long long n = 600851475143LL; // Project Euler #3 input
    cout << "Largest prime factor of " << n << " is " << largestPrimeFactor(n) << "\n";
    return 0;
}
