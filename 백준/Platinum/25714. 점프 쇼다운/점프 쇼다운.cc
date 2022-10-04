#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;

constexpr ll MOD = 1e9 + 7;
template <int mod>
struct ModInt
{
    ll v;
    ModInt(ll _v = 0) : v((_v% mod + mod) % mod) {}
    ModInt& operator+=(const ModInt& rhs) {
        v += rhs.v;
        if (v >= mod) v -= mod;
        return *this;
    }
    ModInt& operator-=(const ModInt& rhs) {
        v -= rhs.v;
        if (v < 0) v += mod;
        return *this;
    }
    ModInt& operator*=(const ModInt& rhs) {
        v *= rhs.v;
        v %= mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& rhs) {
        ll n = mod - 2;
        ModInt rev = 1, b = rhs;
        while (n > 0) {
            if (n & 1) rev *= b;
            b *= b;
            n >>= 1;
        }
        return *this *= rev;
    }
    ModInt operator+(const ModInt& rhs) const {
        ModInt lhs(*this);
        return lhs += rhs;
    }
    ModInt operator-() const { return ModInt() -= *this; }
    ModInt operator-(const ModInt& rhs) const {
        ModInt lhs(*this);
        return lhs -= rhs;
    }
    ModInt operator*(const ModInt& rhs) const {
        ModInt lhs(*this);
        return lhs *= rhs;
    }
    ModInt operator/(const ModInt& rhs) const {
        ModInt lhs(*this);
        return lhs /= rhs;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& n) { return os << n.v; }
    friend std::istream& operator>>(std::istream& is, ModInt& n) {
        ll x;
        is >> x;
        n = ModInt(x);
        return is;
    }
    bool operator==(const ModInt& rhs) const { return v == rhs.v; }
    bool operator!=(const ModInt& rhs) const { return v != rhs.v; }
    ModInt pow(ll k) const {
        ModInt res = 1, p = v;
        while (k > 0) {
            if (k & 1) res *= p;
            p *= p;
            k >>= 1;
        }
        return res;
    }
};
using mint = ModInt<MOD>;

void solve()
{
    int n;
    cin >> n;
    n--;

    vector<mint> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i;
    vector<mint> twop(n + 1);
    twop[0] = 1;
    for (int i = 1; i <= n; ++i) twop[i] = twop[i - 1] * 2;

    mint res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int g1 = i, g2 = j - i - 1, g3 = k - j - 1, g4 = n - 1 - k;
                if (g1 <= 0) g1 = 1;
                if (g2 <= 0) g2 = 1;
                if (g3 <= 0) g3 = 1;
                if (g4 <= 0) g4 = 1;

                mint v = fac[n - 3];
                v /= fac[g1] * fac[g2] * fac[g3] * fac[g4];
                v *= twop[g2 - 1] * twop[g3 - 1];

                res += v;
            }
        }
    }

    cout << res * (n + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}