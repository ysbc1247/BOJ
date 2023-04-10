#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

bool vis[123457];
ll a[123457];
vector<ll>v[123457];
ll res = 0;
ll dfs(ll q, ll b){
    vis[q] = 1;
    ll ans = a[b];
    for(auto i:v[b]){
        if(!vis[i]){
            ans+=dfs(b,i);
        }
    }
    if(ans>0){
        return ans;
    }
    else return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    for(int i=1; i<n; i++){
        char w; ll b,c;
        cin>>w>>b>>c;
        if(w=='W'){
            a[i+1] = -b;
        }
        else a[i+1] = b;
        v[c].push_back(i+1);
        v[i+1].push_back(c);
    }
    cout<<dfs(0,1);
}
