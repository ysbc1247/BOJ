#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;
int n,m;
struct st{
    double a; ll b, c;
}; //각도, 거리, beauty
vector<st>v;
vector<ll>scope;

bool comp(st a, st b){
    return a.a<b.a;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        double a, b; ll c;
        cin>>a>>b>>c;
        double d1 = atan2(a,b);
        double d2 = d1*180/M_PI;
        if(d2<0) d2+=360;
        v.push_back({d2,(ll)pow(a,2)+(ll)pow(b,2),c});
    }
    sort(all(v),comp);
    for(int i=0; i<n; i++){
        if(v[i].a<=90){
            v.push_back({v[i].a+360,v[i].b, v[i].c});
        }
        else break;
    }
    
    for(int i=0; i<m; i++){
        ll a; cin>>a;
        scope.push_back(a);
    }
    ll mx = -1e18;
    for(int i=0; i<m; i++){
        ll r  = scope[i];
        int a = 0; int c; ll mtmp = 0; int b = 0; ll minus = 0;
        for(int k=0; k<v.size(); k++){
            if(v[k].a>v[0].a+90){
                c = k; break;
            }
            if(r>=v[k].b){
                mtmp+=v[k].c;
            }
        }
        for(int k=0; k<v.size(); k++){
            if(v[k].a!=v[0].a){
                b = k; break;
            }
            if(r>=v[k].b){
                minus += v[k].c;
            }
        }
        mx = max(mx, mtmp - r);
        if(a==b) continue;
        if(v[b].a==v[0].a+360){
            continue;
        }
        while(1){
            mtmp -= minus; minus = 0;
            a = b;
            for(int k=c; k<v.size(); k++){
                if(v[k].a>v[a].a+90){
                    c = k; break;
                }
                if(r>=v[k].b){
                    mtmp+=v[k].c;
                }
            }
            for(int k=a; k<v.size(); k++){
                if(v[k].a!=v[a].a){
                    b = k; break;
                }
                if(r>=v[k].b){
                    minus+=v[k].c;
                }
            }
            mx = max(mtmp - r, mx);
            if(b==a) break;
            if(v[b].a==v[0].a+360){
                break;
            }
        }
    }
    cout<<mx; return 0;
}
