#include <bits/stdc++.h>
using namespace std;

int main() {
    long long prev1 = 1;
    long long prev2 = 2;
    long long sum = 2;  
    long long limit = 4000000;

    while (prev1 + prev2 < limit) {
        long long next = prev1 + prev2;
        if (next % 2 == 0) {
            sum += next;
        }
        prev1 = prev2;
        prev2 = next;
    }

    cout << sum << endl;
    return 0;
}
