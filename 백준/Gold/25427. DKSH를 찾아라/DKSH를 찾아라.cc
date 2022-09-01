#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    ll res = 0;
    ll tmp = 0;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
        case 'D': tmp++; break;
        case 'K': a += tmp; break;
        case 'S': b+=a; break;
        case 'H': res += b; break;
        default:break;
        }
    }
    cout << res;
    
}