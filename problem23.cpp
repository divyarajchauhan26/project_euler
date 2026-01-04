#include <bits./stdc++.h>
using namespace std;

int sumOfDivisors(int n) {
    int sum = 1; 
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}
#include <iostream>
#include <vector>
#include <numeric>

// Helper to calculate sum of proper divisors
int getSumOfDivisors(int n) {
    if (n == 1) return 0;
    int sum = 1;
    for (int j = 2; j * j <= n; ++j) {
        if (n % j == 0) {
            sum += j;
            if (j * j != n) { // Don't add the square root twice
                sum += (n / j);
            }
        }
    }
    return sum;
}

int main() {
    const int LIMIT = 28123;
    std::vector<bool> is_abundant(LIMIT + 1, false); // Direct lookup table
    std::vector<int> abundant_list; // Keeps track of abundants found SO FAR
    
    long long total_non_summable = 0;

    for (int i = 1; i <= LIMIT; ++i) {
        // 1. Check if 'i' is abundant
        if (getSumOfDivisors(i) > i) {
            is_abundant[i] = true;
            abundant_list.push_back(i);
        }

        // 2. Check if 'i' can be written as sum of two abundants
        bool can_be_written = false;
        
        for (int a : abundant_list) {
            int b = i - a;
            
            if (b < 12) { 
                // Smallest abundant number is 12. If b < 12, it can't be abundant.
                // Since 'a' is increasing, b will only get smaller, so we can break early!
                break; 
            }

            if (is_abundant[b]) {
                can_be_written = true;
                break; // Found a pair (a + b = i), stop looking
            }
        }

        // 3. If it CANNOT be written, add to answer
        if (!can_be_written) {
            total_non_summable += i;
        }
    }

    std::cout << "Sum of all positive integers which cannot be written as the sum of two abundant numbers: " 
              << total_non_summable << std::endl;

    return 0;
}