#include <bits/stdc++.h>
using namespace std;    

int collatz_sequence_length(long long n) {
    int length = 1;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        length++;
    }
    return length;
}
int main() {
    int max_length = 0;
    int starting_number = 0;

    for (int i = 1; i < 1000000; i++) {
        int length = collatz_sequence_length(i);
        if (length > max_length) {
            max_length = length;
            starting_number = i;
        }
    }

    cout << "Starting number under one million that produces the longest Collatz sequence: " << starting_number << endl;
}