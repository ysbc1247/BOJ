#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;

int main(){
    cin>>t;
    int a = t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll>arr;
        arr.resize(n);
        for(int i=0; i<s.size(); i++){
            arr[i] = (ll)(s[i]-'0');
        }
        vector<ll>dp;
        dp.resize(n);
        ll mx = -1e9;
        if(n%2){
            ll tmp = 0;
            for(int i=0; i<n/2+1; i++){
                tmp +=arr[i];
            }
            dp[n/2]=tmp;
            mx = max(mx,tmp);
            for(int i=n/2+1; i<n; i++){
                dp[i] = dp[i-1]+arr[i]-arr[i-n/2-1];
                mx = max(mx,dp[i]);
            }
        }
        else{
            ll tmp = 0;
            for(int i=0; i<n/2; i++){
                tmp +=arr[i];
            }
            dp[n/2-1]=tmp;
            mx = max(mx,tmp);
            for(int i=n/2; i<n; i++){
                dp[i] = dp[i-1]+arr[i]-arr[i-n/2];
                mx = max(mx,dp[i]);
            }
        }
        cout<< "Case #"<< a-t<< ": "<<mx<<endl;
    }
}