#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

struct st{
    char a;
    string s;
    int b;
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;cin>>n>>m;
    set<int>s;
    for(int i=1; i<=2*n; i++){
        s.insert(i);
    }
    vector<st>v(m);
    int mn = 1e9;
    for(int i=0; i<m; i++){
        cin>>v[i].a>>v[i].s>>v[i].b;
        s.erase(v[i].b);
        mn = min(mn,v[i].b);
    }
    bool chk = 0;
    map<int,st>mp;
    for(int i=0; i<v.size(); i++){
        if(i==v.size()-1){
            if(v[i].a=='A') {
                auto it = s.upper_bound(v[i].b);
                if (it == s.end()) {
                    chk = 1;
                    break;
                }
                int tmp = *it;
                s.erase(tmp);
                mp[v[i].b] = {(v[i].a == 'A' ? 'B' : 'A'), "CHAIN", tmp};
                break;

            }
            else break;
        }
        if(v[i].a==v[i+1].a) {
            auto it = s.upper_bound(v[i].b);
            if (it == s.end()) {
                chk = 1;
                break;
            }
            int tmp = *it;
            s.erase(tmp);
            mp[v[i].b] = {(v[i].a == 'A' ? 'B' : 'A'), "CHAIN", tmp};
        }
    }
    if(chk){
        cout<<"NO";
        return 0;
    }
    if(s.size()%2){
        cout<<"NO";
        return 0;
    }
    if(s.size()){
        if(*s.begin()<mn){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    char nw;
    for(int i=0; i<v.size(); i++){
        cout<<v[i].a<<' '<<v[i].s<<' '<<v[i].b<<'\n';
        nw = v[i].a;
        if(mp.find(v[i].b)!=mp.end()){
            cout<<mp[v[i].b].a<<' '<<mp[v[i].b].s<<' '<<mp[v[i].b].b<<'\n';
            nw = mp[v[i].b].a;
        }
        if(v[i].b==mn){
            for(auto j:s){
                char c = nw=='A'?'B':'A';
                nw = c;
                cout<<c<<' '<<"CHAIN"<<' '<<j<<'\n';
            }
        }
    }
}