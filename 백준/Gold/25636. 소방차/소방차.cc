#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;

struct s {
    ll a, b, c;
};
struct comp {
    bool operator()(const s& a, const s& b) {
        return a.b < b.b;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n; cin >> n;
    vector<ll>w(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> w[i + 1];
    }
    ll m; cin >> m;
    vector<vector<pair<ll, ll>>>v(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    int st, ed; cin >> st >> ed;
    vector<ll>d(n + 1, 1e18);
    vector<ll>a(n + 1, -1e18);
    priority_queue<s,vector<s>,comp>q;
    d[st] = 0; a[st] = w[st];
    q.push({ st,0,w[st] });
    while (!q.empty()) {
        ll now = q.top().a, dis = -q.top().b, wat = q.top().c; q.pop();
        if (d[now] < dis) continue;
        for (auto i : v[now]) {
            ll tmp = i.first; ll ndis = dis + i.second; ll nwat = wat + w[tmp];
            if (ndis<d[tmp]) {
                a[tmp] = nwat, d[tmp] = ndis;
                q.push({ tmp,-ndis,nwat });
            }
            else if (ndis == d[tmp]) {
                if (nwat > a[tmp]) {
                    a[tmp] = nwat;
                    q.push({ tmp,-ndis,nwat });
                }
            }
        }
    }
    if (a[ed] == -1e18) {
        cout << -1; return 0;
    }
    cout << d[ed] << ' ' << a[ed];
}