#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 0, b = 0;
    int n, s; cin >> n >> s;
    int dp[100001] = {};
    for (int i = 0; i < n; i++) {
        int q; cin >> q;
        dp[i + 1] = dp[i] + q;
    }
    int mx = 1e9;
    while (1) {
        if (b == n+1) break;
        if (dp[b] - dp[a] >= s) {
            mx = min(mx, b - a);
            a++; continue;
        }
        else if (dp[b] - dp[a] < s) {
            b++; continue;
        }
    }
    if (mx == 1e9)cout << 0;
    else cout << mx;
}