#include <bits/stdc++.h>
using namespace std;

string number_to_words(int num) {
    static const vector<string> below_20 = {
        "", "one","two","three","four","five","six","seven","eight","nine",
        "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen",
        "seventeen","eighteen","nineteen"
    };
    static const vector<string> tens = {
        "", "", "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"
    };

    string words;
    if (num == 1000)
        return "onethousand";

    if (num >= 100) {
        words += below_20[num / 100] + "hundred";
        num %= 100;
        if (num != 0)
            words += "and"; // add "and" for cases like 115 -> onehundredandfifteen
    }

    if (num >= 20) {
        words += tens[num / 10];
        num %= 10;
    }

    if (num > 0)
        words += below_20[num];

    return words;
}

int main() {
    long long total_letters = 0;
    for (int i = 1; i <= 1000; i++) {
        string w = number_to_words(i);
        total_letters += w.size();
    }
    cout << total_letters << endl; // Should print 21124
}
