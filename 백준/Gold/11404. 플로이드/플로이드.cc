#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


void solve() {
    int n,m;cin>>n>>m;
    vector<vector<ll>>v(n+1,vector<ll>(n+1,1e18));
    for(int i=1; i<=n; i++){
        v[i][i] = 0;
    }
    while(m--){
        ll a, b, c;cin>>a>>b>>c;
        v[a][b] = min(v[a][b],c);
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                v[i][j] = min(v[i][j], v[i][k]+ v[k][j]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            if(v[i][k]==1e18) cout<< 0<< ' '; else
            cout<<v[i][k]<<' ';
        }
        cout<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}