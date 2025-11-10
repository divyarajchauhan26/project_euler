#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> numbers;
    string line;

    while (getline(cin, line)) {
        if (!line.empty())
            numbers.push_back(line);
    }

    long long sum = 0;

    for (const string &num : numbers) {
        // take first 15 digits to avoid overflow
        string firstDigits = num.substr(0, 15);
        sum += stoll(firstDigits);
    }

    string sumStr = to_string(sum);
    cout << "First 10 digits of the sum: " << sumStr.substr(0, 10) << endl;
}
