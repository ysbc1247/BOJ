#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;


bool col[100005] = {};
vector<vector<int>>v;
vector<ll>red, blue;
int r = 0, b = 0;
ll res[100005] = {};
void dfs(int a, int b) {
    for (auto i : v[a]) {
        if (i != b) {
            dfs(i, a);
            res[a] += red[i] * blue[a] + red[a] * blue[i];
            red[a] += red[i]; blue[a] += blue[i];
        }
    }
    if (col[a]) red[a]++;
    else blue[a]++;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    v.resize(n + 1);
    red.resize(n + 1); blue.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> col[i+1];
        if (col[i + 1]) b++;
        else r++;
    }
    for (int i = 0; i < n - 1; i++) {
        int q, w; cin >> q >> w;
        v[q].push_back(w); v[w].push_back(q);
    }
    dfs(1, 0);
    int query; cin >> query;
    while (query--) {
        int a; cin >> a;
        ll ret = res[a];
        if (col[a]) {
            ret += (red[1] - red[a]) * blue[a] + (blue[1] - blue[a]) * (red[a] - 1);
        }
        else {
            ret += (red[1] - red[a]) * (blue[a] - 1) + (blue[1] - blue[a]) * (red[a]);
        }
        cout << ret << '\n';
    }
}