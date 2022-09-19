#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

struct st{
    int d,l,t;
};
int arr[101][100001];
struct comp{
    bool operator() (const st &a, const st &b){
        return a.l<b.l;
    }
};
vector<vector<st>>v(101);
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k,n,r; cin>>k>>n>>r;
    for(int i=0; i<r; i++){
        int s,d,l,t; cin>>s>>d>>l>>t;
        v[s].push_back({d,l,t});
    }
    priority_queue<st,vector<st>,comp> q;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=10000; j++){
            arr[i][j] = 1e9;
        }
    }
    q.push({1,0,0});
    while(!q.empty()){
        int tmp = q.top().d; int dis = -q.top().l; int price = q.top().t;
        q.pop();
        for(int i=0; i<v[tmp].size(); i++){
            int ntmp = v[tmp][i].d; int ndis = dis + v[tmp][i].l; int nprice = price + v[tmp][i].t;
            if(nprice>k) continue;
            if(arr[ntmp][nprice]>ndis){
                arr[ntmp][nprice] = ndis;
                q.push({ntmp,-ndis,nprice});
            }
        }
    }
    int res = 1e9;
    for(int i=0; i<=k; i++){
        res = min(res,arr[n][i]);
    }
    if(res==1e9){
        cout<<-1; return 0;
    }
    cout<<res;
}
