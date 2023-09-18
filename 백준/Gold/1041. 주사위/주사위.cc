#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


void solve() {
    ll n; cin>>n;
    ll a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    if(n==1){
        cout<<a+b+c+d+e+f-max({a,b,c,d,e,f}); return;
    }
    ll C = min({a+c+e,a+d+e,a+b+c,a+b+d,f+d+b,f+d+e,f+e+c,f+c+b});
    ll B = min({e+a,a+b,b+f,f+e,c+e,c+a,c+b,c+f,d+e,d+a,d+b,d+f});
    ll A = min({a,b,c,d,e,f});
    cout<<(n-2)*(5*n-6)*A + (8*n-12)*B+4*C;

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}