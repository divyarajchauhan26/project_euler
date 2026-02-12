#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50 ,100};
    int target = 200;

    vector<long long> dp(target + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int j = coin; j <= target; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[target] << endl;
    return 0;
}
