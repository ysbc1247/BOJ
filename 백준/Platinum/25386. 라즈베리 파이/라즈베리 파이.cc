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

vector<pii>v; int m, n;
bool comp(pii a, pii b) {
    return a.sc < b.sc;
}
ll solve(int a) {
    ll res = 0;
    v[0].fs += m * a;
    if (v[0].sc > v[0].fs) {
        return 1e18;
    }
    res = v[0].fs - v[0].sc;
    int mn = v[0].fs + 1; int mx = v[0].fs + m - 1;
    for (int i = 1; i < n; i++) {
        while (v[i].fs < mn) {
            v[i].fs += m;
        }
        if (v[i].sc > v[i].fs || v[i].fs > mx) {
            return 1e18;
        }
        res += v[i].fs - v[i].sc;
        mn = max(mn, v[i].fs + 1);
    }
    return res;
}

int main() {
    fastio;
    // clock_t start = clock();
    cin >> m >> n;
    v.resize(n);
    rep(i, n) {
        cin >> v[i].fs;
    }
    rep(i, n) {
        cin >> v[i].sc;
    }
    sort(all(v), comp);
    for (int i = 1; i < n; i++) {
        if (v[i - 1].sc == v[i].sc) {
            cout << -1 << endl; return 0;
        }
    }
    if (n == m) {
        rep(i, n) {
            if (v[i].fs != v[i].sc) {
                cout << -1 << endl; return 0;
            }
        }
        cout << 0 << endl; return 0;
    }
    ll res = 1e18;
    for (int i = 0; i < 3; i++) {
        res = min(res, solve(i));
    }
    if (res == 1e18) {
        cout << -1; return 0;
    }
    cout << res;
    // cout<<(double)(clock()-start)/CLOCKS_PER)SEC<<endl;
}