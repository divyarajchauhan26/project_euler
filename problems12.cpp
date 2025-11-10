#include <bits/stdc++.h>
using namespace std;    

int triangle_number(int n){
    return n*(n+1)/2;
}
int count_divisors(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            count++;
            if(i != n / i){
                count++;
            }
        }
    }
    return count;
}

int main(){
    for(int i = 1; ; i++){
        int tri_num = triangle_number(i);
        int div_count = count_divisors(tri_num);
        if(div_count > 500){
            cout << tri_num << endl;
            break;
        }
    }
}