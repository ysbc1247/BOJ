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
bool chk[51]; bool vst[51][51];
int main() {
    fastio;
    //clock_t start = clock();
    cin >> n >> m;
    int a; cin >> a;
    while (a--) {
        int b; cin >> b; chk[b] = 1;
    }
    vector<vector<int>>v(m);
    for (int i = 0; i < m; i++) {
        int a; cin >> a;
        rep(k, a) {
            int c; cin >> c;
            v[i].push_back(c);
        }
    }
    while (1) {
        bool ck = 0;
        rep(i, m) {
            rep(k, v[i].size()) {
                if (chk[v[i][k]]) {
                    if (!vst[i][v[i][k]]) {
                        vst[i][v[i][k]] = 1;
                        rep(j, v[i].size()) {
                            chk[v[i][j]] = 1;
                        }
                        ck = 1;
                        break;
                    }
                }
            }
        }
        if (!ck) {
            break;
        }
    }
    int res = 0;
    rep(i, m) {
        bool ck = 0;
        rep(k, v[i].size()) {
            if (chk[v[i][k]]) {
                ck = 1; break;
            }
        }
        if (!ck) {
            res++;
        }
    }
    cout << res;
    // cout<<(double)(clock()-start)/CLOCKS_PER_SEC<<endl;
}