#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(1, 0); // F1 = 0
    vector<int> b(1, 1); // F2 = 1

    int index = 2;

    while (b.size() < 1000) {
        vector<int> c;
        int carry = 0;

        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int x = (i < a.size()) ? a[i] : 0;
            int y = (i < b.size()) ? b[i] : 0;

            int sum = x + y + carry;
            c.push_back(sum % 10);
            carry = sum / 10;
        }

        if (carry) c.push_back(carry);

        a = b;
        b = c;
        index++;
    }

    cout << index << endl;
    return 0;
}
