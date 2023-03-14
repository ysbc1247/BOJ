#include<bits/stdc++.h>
#define il inline
#define ll long long
#define RE register
#define For(i,a,b) for(RE int (i)=(a);(i)<=(b);(i)++)
#define Bor(i,a,b) for(RE int (i)=(b);(i)>=(a);(i)--)
using namespace std;
const int N = 50005;
int n, a, b, d, mu[N], prime[N], cnt;
bool isprime[N];

int gi() {
    int a = 0; char x = getchar();
    while (x < '0' || x>'9')x = getchar();
    while (x >= '0' && x <= '9')a = (a << 3) + (a << 1) + (x ^ 48), x = getchar();
    return a;
}

il void pre() {
    mu[1] = 1;
    For(i, 2, 50000) {
        if (!isprime[i]) mu[i] = -1, prime[++cnt] = i;
        for (RE int j = 1; j <= cnt && prime[j] * i <= 50000; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
            mu[i * prime[j]] = -mu[i];
        }
    }
    For(i, 1, 50000) mu[i] += mu[i - 1];
}

int solve() {
    if (a > b) swap(a, b);
    a /= d, b /= d;
    int pos = 0, ans = 0;
    for (int i = 1; i <= a; i = pos + 1) {
        pos = min(a / (a / i), b / (b / i));
        ans += (mu[pos] - mu[i - 1]) * (a / i) * (b / i);
    }
    return ans;
}

int main() {
    pre();
    n = gi();
    while (n--) {
        a = gi(), b = gi(), d = gi();
        printf("%d\n", solve());
    }
    return 0;
}