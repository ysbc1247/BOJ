#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    ll n; cin >> n;
    vector<ll>a(n+1);
    for (int i = 0; i < n; i++) {
        ll q; cin >> q; a[i + 1] = a[i] + q;
    }
    ll m; cin >> m; vector<ll>b(m+1);
    for (int i = 0; i < m; i++) {
        ll q; cin >> q; b[i + 1] = b[i] + q;
    }
    ll cnt = 0;
    map<ll, ll>ma, mb;
    for (ll i = 0; i <= n; i++) {
        for (ll k = i + 1; k <= n; k++) {
            ma[a[k] - a[i]]++;
        }
    }
    for (ll i = 0; i <= m; i++) {
        for (ll k = i + 1; k <= m; k++) {
            mb[b[k] - b[i]]++;
        }
    }
    for (auto i : ma) {
        if (mb.find(t - i.first) != mb.end()) {
            cnt += i.second * mb[t - i.first];
        }
    }
    cout << cnt;
}