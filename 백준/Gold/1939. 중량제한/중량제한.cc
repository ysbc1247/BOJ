#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;
int n,m;
int fr,to;
int res = 0;
vector<pair<int,int>>v[100001];
vector<int>d(100001);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<m ;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin>>fr>>to;
    d[fr]=1e9;
    priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>pq;
    pq.push({1e9,fr});
    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        if(p.first<=res) continue;
        if(p.second==to){
            res = max(res,p.first); continue;
        }
        for(auto i:v[p.second]){
            if(i.second<=res) continue;
            if(d[i.first]<min(i.second,p.first)){
                d[i.first] = min(i.second,p.first);
                pq.push({min(i.second,p.first),i.first});
            }
        }
    }
    cout<<res;
}

