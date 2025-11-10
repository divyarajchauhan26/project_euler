#include <bits/stdc++.h>        
using namespace std;

int sum_of_power_two(int exponent) {
    vector<int> digits;
    digits.push_back(1); // Represents 2^0
    for(int i = 0 ; i < exponent;i++){
        int carry = 0;
        for(int j = digits.size() - 1 ; j >=0 ; j--){
            int val = digits[i]*2 + carry;
            digits[j] = val%10;
            carry = val/10;
        }
    }
    int sum = 0;
    for(int digit : digits){
        sum += digit;
    }
}
int main() {
    int exponent = 1000;
    int result = sum_of_power_two(exponent);
    cout << "Sum of the digits of 2^" << exponent << " is: " << result << endl;
    return 0;
}