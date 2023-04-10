#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

ll mod = 123456789;
int a[40005];
ll dp[40005];
vector<int>pr;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    a[0] = a[1] = -1;
    for(int i=2; i<=40004; i++){
        a[i] = i;
    }
    for(int i=2; i<=40004; i++){
        if(a[i]==i){
            for(int k=i*i; k<=40004; k+=i){
                if(a[k]==k){
                    a[k]=i;
                }
            }
        }
    }
    for(int i=2; i<=40004; i++){
        if(a[i]==i){
            pr.push_back(i);
        }
    }
    dp[0] = 1;
    for(int i=0; i<pr.size(); i++){
        for(int k=pr[i]; k<=n; k++){
            dp[k]+=dp[k-pr[i]];
            dp[k]%=mod;
        }
    }
    cout<<dp[n];
}
