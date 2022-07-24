#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define pq priority_queue
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define endl "\n"
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;


int main() {
    fastio;
    int n, q; cin >> n;
    map<int, int>m1, m2;
    map<pii, int>p;
    rep(i, n) {
        int a, b; cin >> a >> b;
        m1[a] = max(m1[a], b);
        if (m2.find(b) == m2.end()) {
            m2[b] = a;
        }
        else {
            m2[b] = min(m2[b], a);
        }
        p[{a, b}] = 1;
    }
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        if (p.find({ a,b })!=p.end()) {
            cout << 1 << endl; continue;
        }
        if (m1.find(a) == m1.end() || m2.find(b) == m2.end()) {
            cout << -1 << endl; continue;
        }
        if (m1[a] > b && m2[b] < a) {
            cout << 2 << endl; continue;
        }
        cout << -1 << endl;
    }
}