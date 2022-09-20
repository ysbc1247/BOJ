#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin>>n;
    int arr[101][101]={};
    vector<pair<int,int>>v;
    int tx,ty;
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            cin>>arr[i][k];
            if(arr[i][k]==1){
                v.push_back({i,k});
            }
            if(arr[i][k]==2){
                tx = i; ty = k;
            }
        }
    }
    bool chk = (tx+ty)%2;
    if(!v.size()){
        cout<<"Undertaker"<<'\n';
        cout<<0; return 0;
    }
    for(auto i:v){
        if((i.first+i.second)%2!=chk){
            cout<<"Shorei"; return 0;
        }
    }
    vector<int>r;
    for(int i=0; i<v.size(); i++){
        r.push_back(i);
    }
    int res = 1e9;
    do{
        int tmp= 0;
        int x = tx; int y = ty;
        for(int i=0; i<r.size(); i++){
            int t = r[i];
            tmp+=max(abs(v[t].first-x),abs(v[t].second-y));
            x = v[t].first; y = v[t].second;
        }
        res = min(res,tmp);
    }while(next_permutation(r.begin(),r.end()));
    cout<<"Undertaker"<<'\n';
    cout<<res;
}
