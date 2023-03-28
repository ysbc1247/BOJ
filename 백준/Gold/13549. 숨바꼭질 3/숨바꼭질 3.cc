#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define pq priority_queue
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;


int main(){
    fastio;
    int n,k;cin>>n>>k;
    vector<vector<pii>>v(100001);
    for(int i=1; i<100000; i++){
        v[i].push_back({i-1,1});
        v[i].push_back({i+1,1});
    }
    v[0].push_back({1,1});
    v[100000].push_back({99999,1});
    for(int i=1; i<=50000; i++){
        v[i].push_back({i*2,0});
    }
    pq<pii>q;
    q.push({0,n});
    int arr[100001]={};
    for(int i=0; i<100001; i++){
        arr[i]=1e9;
    }
    arr[n]=0;
    while(!q.empty()){
        int dis = -q.top().fs;
        int tmp = q.top().sc;
        q.pop();
        for(int i=0; i<v[tmp].size(); i++){
            if(arr[v[tmp][i].fs]>dis+v[tmp][i].sc){
                q.push({-dis-v[tmp][i].sc,v[tmp][i].fs});
                arr[v[tmp][i].fs]=dis+v[tmp][i].sc;
            }
        }
    }
    cout<<arr[k];
}
