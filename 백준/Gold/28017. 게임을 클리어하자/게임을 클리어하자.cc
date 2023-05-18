#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    int arr[501][501]={};
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin>>arr[i][k];
        }
    }
    vector<pair<int,int>>v;
    for(int i=0; i<m; i++){
        v.push_back({arr[0][i],i});
    }
    for(int i=1; i<n; i++){
        sort(all(v));
        int tmp = v[0].second;
        int a = v[0].first, b = v[1].first;
        vector<pair<int,int>>w;
        for(int k=0; k<m; k++){
            if(k==tmp){
                w.push_back({b+arr[i][k],k});
            }
            else w.push_back({a+arr[i][k],k});
        }
        v = w;
    }
    sort(all(v));
    cout<<v[0].first;
}