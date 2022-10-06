#include<bits/stdc++.h>
using ll = long long;
using namespace std;
#define all(v) v.begin(),v.end()


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n,k; cin>>n>>k;
    vector<ll>v(n);
    vector<ll>v2(n);
    for(int i=0; i<n; i++){
        ll a; cin>>a;
        v[i] = a-i*k;
        v2[i] = a-(n-i-1)*k;
    }
    sort(all(v)); sort(all(v2));
    ll ans = min(abs(v[0]-v[n-1]),abs(v2[0]-v2[n-1]));
    cout<<ans/2;
    if(ans&1) cout<<".5";
    else cout<<".0";
}
