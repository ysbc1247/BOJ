#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

struct st{
    int a, b ,c;
};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin>>n;
    st a{}, b{};

    for(int i=0; i<n; i++){
        int d,f,g; cin>>d>>f>>g;
        st q = a, w = b;
        a.a = min(q.a,q.b)+d;
        a.b = min({q.a,q.b,q.c})+f;
        a.c = min(q.b,q.c)+g;
        b.a = max(w.a,w.b)+d;
        b.b = max({w.a,w.b,w.c})+f;
        b.c = max(w.b,w.c)+g;
    }
    cout<<max({b.a,b.b,b.c})<<' '<<min({a.a,a.b,a.c});
}