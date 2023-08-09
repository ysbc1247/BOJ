#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

void solve() {
    int n, q; cin >> n;
    vector<int>v(3e5);
    for (int i = 0; i < n; i++) {
        int a; cin >> a; v[a]++;
    }
    for (int i = 1; i <= 100000; i++) {
        for (int k = 2; k <= 100000; k++) {
            if (i * k > 1e5) break;
            v[i * k] += v[i];
        }
    }
    cin >> q;
    while (q--) {
        int a; cin >> a; cout << v[a] << ' ';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}