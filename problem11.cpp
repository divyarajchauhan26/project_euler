#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 20;
    int grid[20][20];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    long long max_product = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0 ; j<n ; j++){
            //right
            if(j+3<n){
                max_product = max(max_product, 1LL*grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]);
            }
            //down
            if(i+3<n){
                max_product = max(max_product, 1LL*grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
            }
            // diagnol right down
            if(i+3<n && j+3<n){
                max_product = max(max_product, 1LL*grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
            }
            // diagnol left down
            if(i+3<n && j-3>=0){
                max_product = max(max_product, 1LL*grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]);
            }
        }
    }
    cout << max_product << endl;
    return 0;
}