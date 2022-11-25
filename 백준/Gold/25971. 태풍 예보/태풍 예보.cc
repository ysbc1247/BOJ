#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

ll N,K,R,Q;
ll I,X,Y;
vector<ll>dir;
struct st{
    ll a,b,c;
};
vector<st>v;
vector<ll>lu;
ll dis(ll a, ll b, ll x, ll y){
    return(pow(x-a,2)+pow(y-b,2));
}
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
string solve(int dir, ll x, ll y,ll a, ll b){
    if(R<dis(x,y,a,b)){
        return "gori";
    }
    if(dir==1){
        if(b==y) return "gori";
        if(y<b){
            return "safe";
        }
        return "unsafe";
    }
    else if (dir==2){
        if(b==y) return "gori";
        if(y<b){
            return "unsafe";
        }
        return "safe";
    }
    else if (dir==3){
        if(a==x) return "gori";
        if(x<a){
            return "unsafe";
        }
        return "safe";
    }
    else if (dir==4){
        if(a==x) return "gori";
        if(x<a){
            return "safe";
        }
        return "unsafe";
        
    }
    return "1";
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>N>>K>>R>>Q;
    R*=R;
    for(int i=0; i<K; i++){
        cin>>I>>X>>Y;
        v.push_back({I,X,Y});
        lu.push_back(I);
        if(i>=1){
            if(X!=v[i-1].b){
                if(X>v[i-1].b){
                    dir.push_back(1);
                }
                else dir.push_back(2);
            }
            else{
                if(Y>v[i-1].c){
                    dir.push_back(3);
                }
                else dir.push_back(4);
            }
        }
    }
    while(Q--){
        cin>>I>>X>>Y;
        if(I==N){
            cout<<solve(dir[dir.size()-1],v[v.size()-1].b,v[v.size()-1].c,X,Y)<<'\n';
            continue;
        }
        int ix = upper_bound(all(lu),I)-lu.begin();
        int dr = dir[ix-1];
        ll x = v[ix-1].b+(I-lu[ix-1])*dx[dr-1], y = v[ix-1].c+(I-lu[ix-1])*dy[dr-1];
        cout<<solve(dr,x,y,X,Y)<<'\n';
    }
}
