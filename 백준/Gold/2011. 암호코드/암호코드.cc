#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;
const int mod = 1000000;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    string s; cin>>s;
    int dp[5002][2]={};
    if(s[0]>'0'){
        dp[0][0] = 1;
    }
    for(int i=1; i<s.size(); i++){
        if(s[i]!='0'){
            dp[i][0] = dp[i-1][0]+dp[i-1][1];
            dp[i][0]%=mod;
        }
        if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]>='0'&&s[i]<='6')){
            dp[i][1] = dp[i-1][0];
            dp[i][1]%=mod;
        }
    }
    cout<<(dp[s.size()-1][0]+dp[s.size()-1][1])%mod;
}