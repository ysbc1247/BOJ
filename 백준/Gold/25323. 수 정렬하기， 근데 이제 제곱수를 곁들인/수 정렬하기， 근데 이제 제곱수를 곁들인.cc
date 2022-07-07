#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define ll long long
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;

int main(){
    fastio;
    ll n; cin>>n; vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    vector<ll>t=v;
    sort(all(t));
    for(int i=0; i<n; i++){
        ll tmp = gcd(v[i],t[i]);
        if(sqrt(v[i]/tmp)!=ceil(sqrt(v[i]/tmp))||sqrt(t[i]/tmp)!=ceil(sqrt(t[i]/tmp))){
            cout<<"NO"; return 0;
        }
    }
    cout<<"YES";
}
