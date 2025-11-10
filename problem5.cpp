#include <bits/stdc++.h>
using namespace std;

int main(){
    long long ans;
    long long n = 2520;
    while(true){
        bool flag = true;
        for(int i = 1; i <= 20; i++){
            if(n % i != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            ans = n;
            cout << ans << endl;
            break;
        }
        n++;
    }
    return 0;
}