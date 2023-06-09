#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int p[N];
int f(int a){
    if(p[a]==a){
        return a;
    }
    return p[a] = f(p[a]);
}
void mg(int a, int b){
    a = f(a), b = f(b);
    if(a==b)return;
    p[b] = a;
}
int n,m;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        p[i] = i;
    }
    for(int i=1; i<=n*m; i++){
        char c; cin>>c;
        if(c=='U')mg(i-m,i);if (c=='D')mg(i+m,i);if (c=='L')mg(i-1,i);if (c=='R')mg(i+1,i);}
    set<int>s;
    for(int i=1; i<=n*m;i++)s.insert(f(p[i]));cout<<s.size();
}
