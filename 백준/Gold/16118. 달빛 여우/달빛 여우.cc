#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define pq priority_queue
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;


struct my {
    ll a, b, c;
};

struct comp {
    bool operator()(const my& q, const my& w) {
        return q.a < w.a;
    }
};
int main() {
    fastio;
    clock_t start = clock();
    ll fox[4001] = {};
    ll wolf[4001][2] = {};
    ll n, m; cin >> n >> m;
    for (ll i = 0; i <= n; i++) {
        fox[i] = 1e18; wolf[i][0] = 1e18; wolf[i][1] = 1e18;
    }
    fox[1] = 0;
    vector<vector<pll>>v(n + 1);
    for (ll i = 0; i < m; i++) {
        ll a, b, c; cin >> a >> b >> c;
        v[a].push_back({ b,2 * c }); v[b].push_back({ a,2 * c });
    }
    pq<my,vector<my>,comp>q;
    q.push({ 0,1,0 });
    while (!q.empty()) {
        ll tmp = q.top().b; ll dis = -q.top().a; ll state = q.top().c; q.pop();
        if (wolf[tmp][state^1] < dis) continue;
        for (ll i = 0; i < v[tmp].size(); i++) {
            ll nxt = v[tmp][i].fs;
            ll ndis = dis + (state ? v[tmp][i].sc * 2 : v[tmp][i].sc / 2);
            if (ndis < wolf[nxt][state]) {
                wolf[nxt][state] = ndis;
                q.push({ -ndis,nxt,state ^ 1 });
            }
        }
    }
    pq<pll>w;
    w.push({ 0,1 });
    while (!w.empty()) {
        ll tmp = w.top().sc; ll dis = -w.top().fs; w.pop();
        if (fox[tmp] < dis) continue;
        for (ll i = 0; i < v[tmp].size(); i++) {
            ll nxt = v[tmp][i].fs;
            ll ndis = dis + v[tmp][i].sc;
            if(ndis < fox[nxt]) {
                fox[nxt] = ndis;
                w.push({ -ndis,nxt });
            }
        }
    }
    ll res = 0;
    for (ll i = 2; i <= n; i++) {
        if (fox[i] < wolf[i][0] && fox[i] < wolf[i][1]) {
            res++;
        }
    }
    cout << res; 
    //cout << (float)(start - clock()) / CLOCKS_PER_SEC;
}
