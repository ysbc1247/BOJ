#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    while(1){
        int n; cin>>n;
        if(!n){
            return 0;
        }
        if(n==1){
            int a; cin>>a;
            cout<<"homogeneous"<<'\n';
            continue;
        }
        vector<int>v(n+1);
        vector<vector<int>>arr(n+1,v);
        for(int i=0; i<n; i++){
            for(int k=0;k<n; k++){
                cin>>arr[i][k];
            }
        }
        vector<int>m;
        bool chk = 0;
        for(int i=0; i<n-1; i++){
            m.push_back(arr[0][i+1]-arr[0][i]);
        }
        for(int i=0; i<n; i++){
            if(chk)break;
            for(int k=0; k<n-1; k++){
                if(m[k]!=arr[i][k+1]-arr[i][k]){
                    cout<<"not homogeneous"<<'\n';
                    chk = 1; break;
                }
            }if(chk)break;
        }
        if(!chk){
            cout<<"homogeneous"<<'\n';
        }
    }
}

