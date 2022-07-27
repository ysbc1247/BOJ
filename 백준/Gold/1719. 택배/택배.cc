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

int n, m;

int r, a, b, l; int arr[201][201]; vector<vector<pii>>v;
int f[201][201];

void dijk(int a) {
    arr[a][a] = 0;
    pq<pii>q;
    q.push({ 0,a });
    rep(i, v[a].size()) {
        f[a][v[a][i].fs] = v[a][i].fs; arr[a][v[a][i].fs] = v[a][i].sc; q.push({ -v[a][i].sc,v[a][i].fs });
    }
    while (!q.empty()) {
        int tmp = q.top().sc; int dis = -q.top().fs;
        q.pop();
        rep(i, v[tmp].size()) {
            int nxt = v[tmp][i].fs; int nxtd = dis + v[tmp][i].sc;
            if (nxtd < arr[a][nxt]) {
                arr[a][nxt] = nxtd; q.push({ -nxtd,nxt });
                f[a][nxt] = f[a][tmp];
            }
        }
    }
}
int main() {
    fastio;
    // clock_t start = clock();
   
    cin >> n >>r;
    v.resize(n + 1);
    rep(i, r) {
        cin >> a >> b >> l;
        v[a].push_back({ b,l }); v[b].pb({ a,l });
    }
    int mx = -1e9;
    rep(i, n) {
        rep(k, n) {
            arr[i + 1][k+1] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) { 
        dijk(i);
    }
    rep(i, n) {
        rep(k, n) {
            if (arr[i+1][k+1] == 0) {
                cout << '-' << ' ';
            }
            else {
                cout << f[i+1][k+1] << ' ';
            }
        }
        cout << endl;
    }
    // cout<<(double)(clock()-start)/CLOCKS_PER)SEC<<endl;
}