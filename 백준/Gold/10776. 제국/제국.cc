#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;

struct st{
    int a, t,h;
};
struct comp{
    bool operator()(const st&a, const st&b){
        if(a.t==b.t){
            return a.h<b.h;
        }
        return a.t<b.t;
    }
};
struct comp2{
    bool operator()(const st&a, const st&b){
        return a.h<b.h;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k,n,m;
    cin>>k>>n>>m;
    vector<vector<st>>v(n+1);
    for(int i=0; i<m; i++){
        int a,b,t,h;
        cin>>a>>b>>t>>h;
        v[a].push_back({b,t,h});
        v[b].push_back({a,t,h});
    }
    vector<int>vv(200,1e9);
    vector<vector<int>>res(n+1,vv);
    priority_queue<st,vector<st>,comp2>qq;
    priority_queue<st,vector<st>,comp>q;
    int A,B;
    cin>>A>>B;
    qq.push({B,0,0});
    vector<int>dd(n+1,1e9);
    dd[B]=0;
    while(!qq.empty()){
        int tmp = qq.top().a;
        int dis = -qq.top().h;
        qq.pop();
        if(dis>=k){
            continue;
        }
        if(dd[tmp]<dis) continue;
        for(auto i:v[tmp]){
            int ntmp = i.a;
            int ndis = dis+i.h;
            if(ndis>=k){
                continue;
            }
            if(ndis<dd[ntmp]){
                dd[ntmp] = ndis;
                qq.push({ntmp,0,-ndis});
            }
        }
    }
    for(int i=0; i<=200; i++){
        res[A][i] = 0;
    }
    q.push({A,0,0});
    while(!q.empty()){
        int tmp = q.top().a;
        int dis = -q.top().h;
        int time = -q.top().t;
        q.pop();
        if(res[tmp][dis]<time){
            continue;
        }
        if(dis+dd[tmp]>=k){
            continue;
        }
        for(auto i:v[tmp]){
            int ntmp = i.a;
            int ndis = dis+i.h;
            int ntime = time+i.t;
            if(ndis+dd[ntmp]>=k){
                continue;
            }
            if(ndis>=k){
                continue;
            }
            if(res[ntmp][ndis]>ntime){
                q.push({ntmp,-ntime,-ndis});
                res[ntmp][ndis] = ntime;
            }
        }
    }
    int mn = 1e9;
    for(int i=0; i<k; i++){
        mn = min(mn, res[B][i]);
    }
    if(mn==1e9){
        cout<<-1;
    }
    else{
        cout<<mn;
    }
}
