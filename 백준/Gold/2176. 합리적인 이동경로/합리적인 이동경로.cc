#include<bits/stdc++.h>
using namespace std;

struct st{
    int a, b;
};
struct comp{
    bool operator()(const st&a, const st&b){
        return a.b<b.b;
    }
};
int main(){
    int n,m;cin>>n>>m;
    vector<vector<st>>v(n+1);
    for(int i=0; i<m; i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    priority_queue<st,vector<st>,comp>q;
    q.push({2,0});
    vector<int>d(n+1,1e9);
    d[2] = 0;
    vector<int>res(n+1);
    res[2] = 1;
    while(!q.empty()){
        int tmp = q.top().a;
        int dis = -q.top().b;
        q.pop();
        if(d[tmp]<dis) continue;
        for(auto i:v[tmp]){
            int ntmp = i.a; 
            int ndis = dis+i.b;
            if(ndis<d[ntmp]){
                d[ntmp] = ndis;
                q.push({ntmp,-ndis});
            }
            if(dis>d[ntmp]){
                res[tmp]+=res[ntmp];
            }
        }
    }
    cout<<res[1];
}