#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll res = 0;
    ll k; cin >> k;
    for (auto i : v) {
        ll tmp = i;
        while (1) {
            if (tmp > k)break;
            res += (k / tmp);
            tmp *= i;
        }
    }
    cout << res;
}