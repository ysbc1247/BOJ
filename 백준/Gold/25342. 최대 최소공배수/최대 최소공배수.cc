#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;

ll gcd(ll a, ll b){
    while(b!=0){
        ll r = a%b;
        a= b;
        b= r;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a,b);
}

int main(){
    fastio;
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll a = lcm(n,lcm(n-1,n-2));
        ll b = lcm(n,lcm(n-1,n-3));
        ll c = lcm(n,lcm(n-2,n-3));
        ll d = lcm(n-1,lcm(n-2,n-3));
        cout<<max(max(a,d),max(b,c))<<endl;
    }
}
