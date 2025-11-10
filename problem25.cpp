#include <bits/stdc++.h>
using namespace std;    

long long fibonacci(int n) {
    string a = "0", b = "1";
    string c = "";
    for(int i = 2; i <= n; i++) {
        c = "";
        int carry = 0;
        int len_a = a.length();
        int len_b = b.length();
        int max_len = max(len_a, len_b);
        for(int j = 0; j < max_len; j++) {
            int digit_a = (j < len_a) ? a[len_a - 1 - j] - '0' : 0;
            int digit_b = (j < len_b) ? b[len_b - 1 - j] - '0' : 0;
            int sum = digit_a + digit_b + carry;
            c.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        if(carry) {
            c.push_back(carry + '0');
        }
        reverse(c.begin(), c.end());
        a = b;
        b = c;
    }
    return c.length();
}
int main(){
    int result = 0;
    int i =0;
    while(result < 1000){
        result = fibonacci(i);
        i++;
    }
    cout << i - 1 << endl;
    return 0;
}