#include <bits/stdc++.h>
using namespace std;

long long power_two(int exponent) {
    return 1LL << exponent; // Using bitwise shift for 2^exponent
}
int main() {
    int exponent = 1000;
    long long result = power_two(exponent);
    long long sum = 0;
    while (result > 0) {
        sum += result % 10;
        result /= 10;
    }
    cout << "Sum of the digits of 2^" << exponent << " is: " << sum << endl;
    return 0;
}