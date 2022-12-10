#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

struct st {
    ll a, b, c;
};
vector<st>V;
ll p[200002], res;
bool chk;
bool comp(st a, st b) {
    return a.c < b.c;
}
int find(int a) {
    if (a == p[a]) {
        return a;
    }
    return p[a] = find(p[a]);
}
void merge(int a, int b) {
    chk = 0;
    a = find(a); b = find(b);
    if (a == b) return;
    p[a] = b;
    chk = 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        int v, e; cin >> v >> e; if (!v && !e) return 0;
        V.clear(); res = 0; chk = 0; memset(p, 0, sizeof(p));
        ll mx = 0;
        for (int i = 0; i <= v; i++) {
            p[i] = i;
        }
        for (int i = 0; i < e; i++) {
            ll a, b, c; cin >> a >> b >> c;
            mx += c;
            V.push_back({ a,b,c });
        }
        sort(all(V), comp);
        for (int i = 0; i < e; i++) {
            merge(V[i].a, V[i].b);
            if (chk) res += V[i].c;
        }
        cout << mx - res << '\n';
    }
}