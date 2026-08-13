#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    long long sum = accumulate(coins.begin(), coins.end(), 0LL);

    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for(int i = 1; i <= n; i++) {
        for(int j = sum; j >= coins[i-1] ; j--) {
            dp[j] = (dp[j] || dp[j-coins[i-1]]);
        }
    }

    long long cnt = 0;
    for(int i = 1; i <= sum; i++) {
        if(dp[i]) cnt++;
    }

    cout << cnt << "\n";
    for(int i = 1; i <= sum; i++) {
        if(dp[i]) cout << i << " ";
    }

    return 0;
}