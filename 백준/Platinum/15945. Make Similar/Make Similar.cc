#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin>>n; vector<ll>v(n);
    for(int i=0; i<n ;i++){
        cin>>v[i];
    }
    sort(all(v));
    if(v[0]<0&&v[n-1]>0){
        cout<<0; return 0;
    }
    cout<<min(min(abs(v[0]),abs(v[n-1])),abs(v[n-1]-v[0]));
}

