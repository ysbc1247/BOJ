#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    map<ll, ll>mp;
    ll n, q; cin >> n >> q;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; mp[v[i]]++;
    }
    bool z = 0;
    while (q--) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            if (n == 1) {
                cout << 0 << '\n'; continue;
            }
            if (!b) {
                cout << (z ? 1 : 0) << '\n'; continue;
            }
            bool chk = 0;
            for (int i = 1; i <= sqrt(b); i++) {
                if (!(b%i)) {
                    if (i * i == b) {
                        if (mp[i] >= 2) {
                            chk = 1; break;
                        }
                    }
                    else if (mp[i] && mp[b / i]) {
                        chk = 1; break;
                    }
                }
            }
            cout << (chk ? 1 : 0) << '\n';
        }
        else {
            z = 1;
            mp[v[b - 1]]--;
            v[b - 1] = 0;
        }
    }
}