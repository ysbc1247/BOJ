#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()


bool chk[4000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int>v;
    chk[0] = chk[1] = 1;
    v.push_back(0);
    for (int i = 2; i <= sqrt(n); i++) {
        if (!chk[i]) {
            for (int k = 2*i; k <= n; k+=i) {
                chk[k] = 1;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        if (!chk[i]) v.push_back(i);
    }
    int st = 0, ed = 0;
    int cnt = 0;
    int sum = 0;
    while (1) {
        if (ed >= v.size()) break;
        if (sum == n) {
            cnt++; ed++; if (ed == v.size()) break; sum += v[ed]; continue;
        }
        if (sum > n) {
            sum -= v[st]; st++;  continue;
        }
        if (sum < n) {
            ed++; if (ed == v.size()) break; sum += v[ed]; continue;
        }
    }
    cout << cnt;
}