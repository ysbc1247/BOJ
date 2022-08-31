#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<string>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(all(v));
        bool chk = 0;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].size() < v[i].size()) continue;
            if (v[i + 1].substr(0, v[i].size()) == v[i]) {
                chk = 1; break;
            }
        }
        if (chk) {
            cout << "NO" << '\n'; continue;
        }
        cout << "YES" << '\n';
    }
}