#include <bits/stdc++.h>
using namespace std;

// Function to compute alphabetical value of a name
int name_value(const string &s) {
    int sum = 0;
    for (char c : s)
        sum += (c - 'A' + 1); // 'A' -> 1, 'B' -> 2, ...
    return sum;
}

int main() {
    // Step 1: Read the file content
    ifstream file("0022_names.txt");
    if (!file.is_open()) {
        cerr << "Error: could not open file.\n";
        return 1;
    }

    string content;
    getline(file, content); // The file is one long line
    file.close();

    // Step 2: Parse names (remove quotes, split by commas)
    vector<string> names;
    string current = "";
    for (char c : content) {
        if (c == '"') continue;       // ignore quotes
        if (c == ',') {               // end of a name
            names.push_back(current);
            current.clear();
        } else {
            current += c;
        }
    }
    if (!current.empty()) names.push_back(current); // last name

    // Step 3: Sort alphabetically
    sort(names.begin(), names.end());

    // Step 4: Compute total score
    long long total_score = 0;
    for (int i = 0; i < (int)names.size(); ++i) {
        total_score += 1LL * (i + 1) * name_value(names[i]);
    }

    // Step 5: Print result
    cout << "Total of all name scores = " << total_score << endl;

    return 0;
}
