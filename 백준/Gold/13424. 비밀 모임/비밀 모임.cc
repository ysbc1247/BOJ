#include<bits/stdc++.h>
using ll = long long;
using namespace std;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,int>>>v(n+1);
        for(int i=0; i<m; i++){
            int a, b, c; cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
        vector<int>r;
        int q; cin>>q;
        while(q--){
            int w;
            cin>>w;
            r.push_back(w);
        }
        vector<int>dd(n+1,1e9);
        vector<vector<int>>d;
        for(int i=0; i<n+1; i++){
            d.push_back(dd);
        }
        for(int i=1; i<=n; i++){
            d[i][i] = 0;
            priority_queue<pair<int,int>>pq;
            pq.push({i,0});
            while(!pq.empty()){
                int tmp = pq.top().first;
                int dis = -pq.top().second;
                pq.pop();
                for(auto k:v[tmp]){
                    int ntmp = k.first;
                    int ndis  = dis+k.second;
                    if(d[i][ntmp]>ndis){
                        d[i][ntmp] = ndis;
                        pq.push({ntmp,-ndis});
                    }
                }
            }
        }
        int ret = 1e9;
        int rr;
        for(int i=1; i<=n; i++){
            int tmp = 0;
            for(auto k:r){
                tmp+=d[i][k];
            }
            if(tmp<ret){
                ret = tmp;
                rr=i;
            }
        }
        cout<<rr<<'\n';
    }
    
}

