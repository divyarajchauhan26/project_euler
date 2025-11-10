#include <bits/stdc++.h>
using namespace std;

vector<int> sieve_of_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (is_prime[i]){
            primes.push_back(i);
        }
    return primes;
}

int main() {
    int limit = 2000000; // increased upper bound safely
    vector<int> primes = sieve_of_eratosthenes(limit);
    long long sum = 0;
    for (int prime : primes) {
        sum += prime;
    }
    cout << sum << endl;
    return 0;
}
