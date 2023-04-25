#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<long double, long double>>v(n);
        for(int i=0; i<n; i++){
            cin>>v[i].first>>v[i].second;
        }
        long double mx = 1e18;
        sort(all(v));
        vector<int>c(n,0);
        for(int i=0; i<c.size(); i+=2) c[i] = 1;
        sort(all(c));
        do{
            long double x = 0,y = 0;
            for(int i=0; i<n; i++){
                if(c[i]) x+=v[i].first,y+=v[i].second;
                else x-=v[i].first, y-=v[i].second;
            }
            mx = min(mx, sqrt(x*x+y*y));
        }while(next_permutation(all(c)));
        
        cout<<setprecision(15);
        cout<<mx<<'\n';
    }
}
