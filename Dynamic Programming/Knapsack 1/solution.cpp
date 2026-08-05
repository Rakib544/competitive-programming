#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> weights(n);
    vector<int> values(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    } 

    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            if(j >= weights[i-1]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << "\n";
    return 0;
}