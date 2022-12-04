#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int d; cin >> d;
    vector<int>v(d);
    for (int i = 0; i < d; i++) {
        cin >> v[i];
    }
    int s, e; cin >> s >> e;
    vector<double>dp(s + e + 1);
    double a = 1, b = 3 * e + 1;
    for (int i = 0; i < 50; i++) {
        double c = (a + b) / 2;
        for (int k = s + e - 1; k >= 0; k--) {
            if (k >= s) {
                if (k > e) {
                    dp[k] = c;
                }
                else {
                    dp[k] = 0;
                }
            }
            else {
                dp[k] = 1e9;
                for (int j = 0; j < d; j++) {
                    dp[k] = min(dp[k], (dp[k + 1] - dp[k + v[j] + 1]) / v[j]);
                }
                dp[k]++;
            }
            dp[k] += dp[k + 1];
        }
        if (dp[0] - dp[1] > c) {
            a = c;
        }
        else {
            b = c;
        }
    }
    cout << fixed;
    cout << setprecision(11);
    cout << a << '\n';
}
