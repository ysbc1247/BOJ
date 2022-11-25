#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;

struct st{
    ll a, b, c;
};
struct comp{
    bool operator()(const st &a, const st &b){
        if(a.a==b.a){
            if(a.b==b.b){
                return a.c>=b.c;
            }
            return a.b>b.b;
        }
        return a.a>b.a;
    }
};
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    ll n; cin>>n;
    clock_t start = clock();
    ll a = floor(cbrt(n)), b = ceil(cbrt(n));
    ll mx = 1e18;
    priority_queue<st,vector<st>,comp> q;
    priority_queue<st,vector<st>,comp> emp;
    for(ll i=max(1LL,a-3000); i<=b+2000; i++){
        for(ll k = i; k<=i + 4000; k++){
            ll j = n/(i*k);
            if(i*k*j<n){
                j++;
            }
            if(2*(i*k+k*j+j*i)<mx){
                vector<ll>v;
                v.push_back(i); v.push_back(k); v.push_back(j);
                sort(all(v));
                q = emp;
                q.push({v[0],v[1],v[2]});
                mx = 2*(i*k+k*j+j*i);
            }
            else if (2*(i*k+k*j+j*i)==mx){
                vector<ll>v;
                v.push_back(i); v.push_back(k); v.push_back(j);
                sort(all(v));
                q.push({v[0],v[1],v[2]});
            }
        }
    }
    cout<<q.top().a<<' '<<q.top().b<<' '<<q.top().c;
    //cout<<(double)(clock()-start)/CLOCKS_PER_SEC;
}
