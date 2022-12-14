#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[1001][3] = {};
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int dp[1001][3] = {};
    int mn = 1e9;
    dp[0][0] = arr[0][0], dp[0][1] = 1e9, dp[0][2] = 1e9;
    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][2] + arr[i][1], dp[i - 1][0] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }
    mn = min({ mn,dp[n - 2][0] + arr[n - 1][1],dp[n - 2][0] + arr[n - 1][2],dp[n - 2][2] + arr[n - 1][1],dp[n - 2][1] + arr[n - 1][2] });
    dp[0][0] = 1e9, dp[0][1] = arr[0][1], dp[0][2] = 1e9;
    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][2] + arr[i][1], dp[i - 1][0] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }
    mn = min({ mn,dp[n - 2][0] + arr[n - 1][2],dp[n - 2][1] + arr[n - 1][2],dp[n - 2][1] + arr[n - 1][0],dp[n - 2][2] + arr[n - 1][0] });
    dp[0][0] = 1e9, dp[0][1] = 1e9, dp[0][2] = arr[0][2];
    for (int i = 1; i < n - 1; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][2] + arr[i][1], dp[i - 1][0] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }
    mn = min({ mn,dp[n - 2][0] + arr[n - 1][1],dp[n - 2][1] + arr[n - 1][0],dp[n - 2][2] + arr[n - 1][1],dp[n - 2][2] + arr[n - 1][0] });
    cout << mn;
}