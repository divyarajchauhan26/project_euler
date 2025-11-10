#include <bits/stdc++.h>
using namespace std;

int sum_of_proper_divisors(int n) {
    int sum = 1; // 1 is a proper divisor of any n > 1
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
bool is_amicable(int a, int b) {
    return a != b && sum_of_proper_divisors(a) == b && sum_of_proper_divisors(b) == a;
}

int main() {
    const int limit = 10000;
    int amicable_sum = 0;
    for (int i = 2; i < limit; i++) {
        int partner = sum_of_proper_divisors(i);
        if (is_amicable(i, partner)) {
            amicable_sum += i;
        }
    }
    cout << "Sum of all amicable numbers under " << limit << " is: " << amicable_sum << endl;
    return 0;
}