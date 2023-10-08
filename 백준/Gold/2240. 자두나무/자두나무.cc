#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int  t, w; cin >> t >> w;
    vector<int>v(t+1);
    for (int i = 0; i < t; i++) {
        cin >> v[i + 1];
    }
    if (t == 1) {
        if (!w) {
            if (v[1] == 1) {
                cout << 1;
            }
            else cout << 0;
            return 0;
        }
        cout << 1; return 0;
    }
    int dp[1005][35][3] = {};
    for (int i = 1; i <= t; i++) {
        for (int k = 0; k <= w; k++) {
            dp[i + 1][k][0] = max(dp[i + 1][k][0], dp[i][k][0]);
            dp[i + 1][k][1] = max(dp[i + 1][k][1], dp[i][k][1]);
            if (v[i] == 2) {
                if(dp[i][k][1])
                dp[i + 1][k][1] = max(dp[i + 1][k][1], dp[i][k][1] + 1);
                dp[i + 1][k + 1][1] = max(dp[i + 1][k + 1][1], dp[i][k][0] + 1);
            }
            else {
                dp[i + 1][k][0] = max(dp[i + 1][k][0], dp[i][k][0] + 1);
                if(dp[i][k][1])
                dp[i + 1][k + 1][0] = max(dp[i + 1][k + 1][0], dp[i][k][1] + 1);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i <= w; i++) {
        mx = max({ mx,dp[t + 1][i][0],dp[t + 1][i][1] });
    }
    cout << mx;
}