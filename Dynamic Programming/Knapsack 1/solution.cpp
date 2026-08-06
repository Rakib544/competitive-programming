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

    vector<ll> dp(w+1, 0);
    for(int i = 0; i < n; i++) {
        for(int j = w; j >= weights[i]; j--) {
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }
    cout << dp[w] << "\n";
    return 0;
}