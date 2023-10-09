#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
struct st{
    int a, b, c;
};
struct compare {
    bool operator()(const st& s1, const st& s2) {
        return s1.a < s2.a;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int arr[1002][1002]={};
    bool b[1000005]={};
    priority_queue<st,vector<st>,compare>pq;
    for(int i=1; i<=n; i++){
        for(int k=1; k<=m; k++){
            cin>>arr[i][k];
            if(i==1||i==n||k==1||k==m){
                b[arr[i][k]]=1;
                pq.push({arr[i][k],i,k});
            }
        }
    }
    int a; cin>>a;
    while(a--){
        st q = pq.top();
        pq.pop();
        int x = q.b, y = q.c;
        cout<<x<< ' '<<y<<'\n';
        for(int i=0; i<4; i++) {
            int tmpx = x + dx[i], tmpy = y + dy[i];
            if (!b[arr[tmpx][tmpy]]) {
                b[arr[tmpx][tmpy]]=1;
                pq.push({arr[tmpx][tmpy],tmpx,tmpy});
            }
        }
    }

}