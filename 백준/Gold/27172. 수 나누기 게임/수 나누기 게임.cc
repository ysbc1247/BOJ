#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    map<int,int>mp;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        mp[v[i]] = 0;
    }
    for(auto i:mp){
        for(int k=1; k*k<=i.first; k++){
            if(i.first%k==0){
                if(mp.find(i.first/k)!=mp.end()){
                    mp[i.first]--;
                    mp[i.first/k]++;
                }
                if(i.first!=k*k){
                    if(mp.find(k)!=mp.end()){
                        mp[i.first]--;
                        mp[k]++;
                    }
                }
            }
        }
    }
    for(auto i:v){
        cout<<mp[i]<<' ';
    }
}
