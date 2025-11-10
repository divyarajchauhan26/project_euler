#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>> & triangle , int i , int j){
    if(i == triangle.size()){
        return 0;
    }
    return triangle[i][j] + max(maxPathSum(triangle , i+1 , j) , maxPathSum(triangle , i+1 , j+1));
}
int main() {
    vector<vector<int>> triangle;
    string line;

    cout << "Enter the triangle (blank line to stop):\n";
    while (true) {
        getline(cin, line);
        if (line.empty())
            break;
        stringstream ss(line);
        vector<int> row;
        int num;

        while (ss >> num)
            row.push_back(num);

        triangle.push_back(row);
    }
    int n = triangle.size();
    int num = 0;
    num = maxPathSum(triangle , 0 , 0);
    cout << "The sum of the maximum path is: " << num << endl;
   
    return 0;
}
