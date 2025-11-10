#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr;
    for(int i = 1; i < 1000; i++) arr.push_back(i); // numbers up to 999

    for(int i = arr.size() - 1; i >= 0; i--) {
        int c = arr[i];
        int c2 = c * c;
        int left = 0;
        int right = i - 1; // only consider numbers < c

        while(left < right) {
            int sum = arr[left]*arr[left] + arr[right]*arr[right];
            if(sum == c2 && arr[left] + arr[right] + c == 1000) {
                cout << "a=" << arr[left] << " b=" << arr[right] << " c=" << c << endl;
                cout << "Product abc = " << arr[left]*arr[right]*c << endl;
                return 0;
            } else if(sum < c2) {
                left++;
            } else {
                right--;
            }
        }
    }

    return 0;
}
