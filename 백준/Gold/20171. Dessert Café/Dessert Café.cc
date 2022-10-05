#include<bits/stdc++.h>
using ll = long long;
using namespace std;
#define all(v) v.begin(),v.end()

int n,k, visited[100001];
vector<int>v[100001];
set<int>s;
int res;
bool ret[100001];
bool dfs(int a){
    visited[a] = 1;
    bool chk = 0;
    for(auto i:v[a]){
        if(visited[i]) continue;
        if(s.find(i)!=s.end()){
            chk = 1;
        }
        else if (!visited[i]){
            if(dfs(i)) chk =1;
        }
    }
    if(!chk&&s.find(a)==s.end()){
        return 0;
    }
    res++;
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n-1; i++){
        int a,b,c; cin>>a>>b>>c;
        v[a].push_back(b); v[b].push_back(a);
    }
    for(int i=0; i<k; i++){
        int a; cin>>a;
        ret[a] = 1;
        s.insert(a);
    }
    for(auto i:s){
        dfs(i);
    }
    cout<<res;
}
