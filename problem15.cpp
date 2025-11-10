// #include <bits/stdc++.h>
// using namespace std;

// long long factorial(int n) {
//     if (n == 0 || n == 1) return 1;
//     return n * factorial(n - 1);
// }

// long long calculate_steps(int n) {
//     int total = n + n;
//     long long steps = factorial(total) / (factorial(n) * factorial(n));
//     return steps;
// }

// int main() {
//     int n = 20;
//     long long steps = calculate_steps(n);
//     cout << "Number of lattice paths in a " << n << "x" << n << " grid: " << steps << endl;
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

long long latticePaths(int n) {
    long long result = 1;
    // Compute C(2n, n) using the multiplicative formula
    for (int i = 1; i <= n; i++) {
        result = result * (n + i) / i;  // multiply first, then divide
    }
    return result;
}

int main() {
    int n = 20;
    long long steps = latticePaths(n);
    cout << "Number of lattice paths in a " << n << "x" << n << " grid: " << steps << endl;
    return 0;
}
