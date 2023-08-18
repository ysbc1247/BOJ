#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

const int MOD = 1e9 + 7; // change this to your required value

long long mod_pow(long long base, int exp, int MOD) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long mod_inv(long long x, int MOD) {
    return mod_pow(x, MOD - 2, MOD); // Fermat's Little Theorem
}

long long factorial_mod(int n, int MOD) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

long long nCk_mod(int n, int k, int MOD) {
    if (k > n) return 0;
    long long numerator = factorial_mod(n, MOD);
    long long denominator = (factorial_mod(k, MOD) * factorial_mod(n - k, MOD)) % MOD;
    return (numerator * mod_inv(denominator, MOD)) % MOD;
}

void solve() {
    int k, n; cin >> n >> k;
    vector<int>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll res = 1;
    for (int i = 1; i <= k - 1; i++) {
        res *= 2; res %= MOD;
    }
    res *= nCk_mod(n, k, MOD);
    res %= MOD;
    cout << res;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; 
    while (t--) {
        solve();
    }
}