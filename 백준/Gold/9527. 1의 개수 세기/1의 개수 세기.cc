#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

ll a, b;

ll sum(ll x) {
    x++;
    ll a = x, b = 1, ret = 0;
    while (a) {
        if (x & b) ret += x % b + (x - x % (b * 2)) / 2;
        else ret += (x - x % b) / 2;
        b <<= 1;
        a >>= 1;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    cout << sum(b) - sum(a - 1) << '\n';
}
