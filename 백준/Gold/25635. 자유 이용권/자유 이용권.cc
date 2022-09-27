#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main() {
    ll n; cin >> n; vector<ll>v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    ll tmp = 0;
    for (int i = 0; i < n - 1; i++) tmp += v[i];
    if (v[n - 1] - tmp >= 2) cout << 2 * tmp + 1; 
    else cout << tmp + v[n - 1];
}