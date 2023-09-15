#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


void solve() {
    int n, m;
    cin >> n >> m;
    char a[12][12] = {};
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> a[i][k];
        }
    }
    int mx = -1;
    for (int q = 0; q < n; q++) {
        for (int j = 0; j < m; j++) {
            for (int i = -11; i <= 11; i++) {
                for (int k = -11; k <= 11; k++) {
                    if(!i&&!k) continue;
                    string s = "";
                    int qq = q, ww = j;
                    while(1){
                        if(qq>=n||qq<0||ww>=m||ww<0) break;
                        s += a[qq][ww];
                        if(sqrt(stol(s))==ceil(sqrt(stol(s)))){
                            mx = max(mx,stoi(s));
                        }
                        qq+=i, ww+=k;
                    }
                }
            }
        }
    }
    cout<<mx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}