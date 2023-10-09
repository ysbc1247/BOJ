#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

vector<int>a;
int c(int w, int b){
    return (w+b)%3;
}
void d(int w, int b){
    a[w] = c(a[w],b);
    a[w+1] = c(a[w+1],b);
    a[w+2] = c(a[w+2], b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        char c; cin>>c;
        v[i] = (c=='R'?0:c=='G'?1:2);
    }

    int mx = 1e9;
    for(int k=3; k<=5; k++) {
        a = v;
        int tmp = 0;
        for (int i = 0; i < n - 2; i++) {
            int q = (k - a[i]) % 3;
            tmp += q;
            d(i, q);
        }
        if (a[n - 2] == k-3 && a[n - 1] == k-3) {
            mx = min(mx, tmp);
        }
    }
    cout<<(mx==1e9?-1:mx);
}