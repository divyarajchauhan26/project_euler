#include <bits/stdc++.h>
using namespace std;    

int sum_till_n(int n){
    return n * (n + 1) / 2;
}
int sum_of_squares_till_n(int n){
    return n * (n + 1) * (2 * n + 1) / 6;
}
int main(){
    int n = 100;
    int sum1 = sum_till_n(n);
    int sum2 = sum_of_squares_till_n(n);
    int ans = sum1 * sum1 - sum2;
    cout << ans << endl;
    return 0;
}