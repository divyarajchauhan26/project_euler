#include <bits/stdc++.h>
using namespace std;

long long sum_multiples_below(long long limit, long long k) {
    long long n = (limit - 1) / k;           
    return k * (n * (n + 1) / 2);         
}

int main() {
    long long limit = 1000;
    long long result = sum_multiples_below(limit, 3)
                     + sum_multiples_below(limit, 5)
                     - sum_multiples_below(limit, 15); 
    cout << result << '\n';
    return 0;
}
