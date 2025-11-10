// #include <bits/stdc++.h>
// using namespace std;

// long long factorial(long long n) {
//     if (n <= 1) return 1;
//     return n * factorial(n - 1);
// }
// long long  sumOfDigits(long long n) {
//     long long sum = 0;
//     while (n > 0) {
//         sum += n % 10;
//         n /= 10;
//     }
//     return sum;
// }

// int main() {
//     int n = 100;
//     long long fact = factorial(n);
//     long long result = sumOfDigits(fact);
//     cout << "The sum of the digits in " << n << "! is: " << result << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Multiply two big numbers represented as strings
string multiplyStrings(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    
    // Result can be at most n1+n2 digits
    vector<int> result(n1 + n2, 0);

    // Multiply each digit
    for (int i = n1 - 1; i >= 0; i--) {
        for (int j = n2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1]; // add existing value at this position
            result[i + j + 1] = sum % 10;     // store the digit
            result[i + j] += sum / 10;        // carry to the next left position
        }
    }

    // Convert result to string
    string resStr;
    for (int num : result) {
        if (!(resStr.empty() && num == 0))  // skip leading zeros
            resStr.push_back(num + '0');
    }

    return resStr.empty() ? "0" : resStr;
}

string factorial(string n){
    string result = "1";
    for (int i = 2; i <= stoi(n); i++) {
        result = multiplyStrings(result, to_string(i));
    }
    return result;
}

int main() {
    string n = "10";
    string fact = factorial(n);
    
    // Calculate sum of digits
    long long sum = 0;
    for (char digit : fact) {
        sum += (digit - '0');
    }

    cout << "The sum of the digits in " << n << "! is: " << sum << endl;
    return 0;
}
