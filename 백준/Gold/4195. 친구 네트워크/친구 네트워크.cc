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

int p[200005];
int sz[200005];
bool c1, c2;
int find(int u) {
    if (u == p[u]) {
        return u;
    }
    return p[u] = find(p[u]);
}
void merge(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return;
    if (sz[u] > sz[v]) swap(u, v);
    p[u] = v;
    sz[v] += sz[u]; return;

}
int main() {
    fastio;
    // clock_t start = clock();
    int t; cin >> t;
    while (t--) {
        rep(i, 200005) {
            p[i] = i;
        }
        rep(i, 200005) {
            sz[i] = 1;
        }
        int f; cin >> f;
        map<string, int >mp; int tmp = 0;
        while (f--) {
            c1 = 0; c2 = 0;
            string a, b;
            int u, v;
            cin >> a >> b;
            if (mp.find(a) == mp.end()) {
                tmp++; mp[a] = tmp;
                c1 = 1;
            }
            u = mp[a];
            if (mp.find(b) == mp.end()) {
                tmp++; mp[b] = tmp;
                c2 = 1;
            }
            v = mp[b];
            merge(u, v);
            cout << max(sz[p[u]],sz[p[v]]) << endl;
        }
    }
    // cout<<(double)(clock()-start)/CLOCKS_PER)SEC<<endl;
}