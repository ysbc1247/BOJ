#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

ll arr[2002][2002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,q;cin>>n>>m>>q;
    for(int i=1; i<=n; i++){
        for(int k=1; k<=m; k++){
            cin>>arr[i][k];
        }
    }
    for(int i=1; i<=m; i++){
        for(int k=1; k<=n; k++){
            arr[k][i]+=arr[k-1][i];
        }
    }
    for(int i=1; i<=m; i++){
        for(int k=1; k<=n; k++){
            arr[k][i]+=arr[k-1][i-1];
        }
    }
    while(q--){
        int a, b; cin>>a>>b;
        cout<<arr[a][b]<<'\n';
    }
}