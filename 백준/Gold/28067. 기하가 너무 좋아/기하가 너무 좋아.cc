#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int c(pair<int,int>a, pair<int,int>b){
    return pow(a.first-b.first,2)+pow(a.second-b.second,2);
}
bool areCollinear(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int x1 = p1.first;
    int y1 = p1.second;

    int x2 = p2.first;
    int y2 = p2.second;

    int x3 = p3.first;
    int y3 = p3.second;

    int a = (y2 - y1) * (x3 - x2);
    int b = (y3 - y2) * (x2 - x1);
    return a == b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    set<tuple<int,int,int>>s;
    double n,m; cin>>n>>m;
    vector<pair<int,int>>v;
    for(int i=0; i<=n; i++){
        for(int k=0; k<=m; k++){
            v.push_back({i,k});
        }
    }
    for(int i=0; i<v.size(); i++){
        for(int k=i+1; k<v.size(); k++){
            for(int j=k+1; j<v.size(); j++){
                if(areCollinear(v[i],v[k],v[j]))continue;
                int a = c(v[i],v[k]),b = c(v[k],v[j]), w = c(v[i],v[j]);
                vector<int>vv;
                vv.push_back(a);vv.push_back(b);vv.push_back(w);
                sort(all(vv));
                s.insert({vv[0],vv[1],vv[2]});
            }
        }
    }
    cout<<s.size();
}
