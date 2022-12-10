#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

struct st {
    double a, b;
};
st p;
double solve(st a, st b) {
    return 0.5 * ((p.a * a.b + a.a * b.b + b.a * p.b) - (a.a * p.b + b.a * a.b + p.a * b.b));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    double res = 0;
    vector<st>v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b;
    }
    p = v[0];
    for (int i = 1; i < n; i++) {
        res += solve(v[i - 1], v[i]);
    }
    res = abs(res);
    cout << fixed;
    cout << setprecision(1) << res;
}
