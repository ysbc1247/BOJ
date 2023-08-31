#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


void solve() {
    map<int,int>mp;
    int n; cin>>n;
    vector<pair<int,int>>v,r;
    for(int i=0; i<n; i++){
        int a; cin>>a; mp[a]++;
        v.push_back({a,i});
    }
    sort(all(v));
    int mx = 0;
    for(auto i:mp){
        mx = max(i.second, mx);
    }
    if(mx>n/2){
        cout<<-1; return;
    }
    for(int i=0; i<n-mx; i++){
        r.push_back({v[i+mx].second,v[i].first});
    }
    for(int i=n-mx; i<n; i++){
        r.push_back({v[i-n+mx].second,v[i].first});
    }
    sort(all(r));
    for(auto i:r){
        cout<<i.second<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}