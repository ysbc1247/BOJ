#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, K; cin >> n >> K;
    vector<int>v(n+1), q(n+1);
    for (int i = 0; i < n; i++) {
        cin >> v[i+1];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i+1];
    }
    map<int, int>mp;
    mp[100] = 0;
    for (int i = 1; i <= n; i++) {
        map<int, int>m;
        for (auto k : mp) {
            m[min(100, k.first + K)] = max(k.second, m[min(100, k.first + K)]);
            if (k.first - q[i] < 0) continue;
            m[min(100,k.first - q[i] + K)] = max(m[min(100, k.first - q[i] + K)], k.second + v[i]);
        }
        mp = m;
    }
    int mx = 0;
    for (auto i : mp) {
        mx = max(i.second, mx);
    }
    cout << mx;
}