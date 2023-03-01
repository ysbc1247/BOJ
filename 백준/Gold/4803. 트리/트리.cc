#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;

int n, m;
vector<vector<int>>v;
bool vis[502];
bool chk = 0;
void dfs(int a, int b) {
    if (chk)return;
    if (vis[a]) {
        chk = 1; return;
    }
    vis[a] = 1;
    for (auto i : v[a]) {
        if(i!=b)
        dfs(i, a);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cs = 0;
    while (1) {
        cs++;
        cin >> n >> m;
        int res = 0;
        memset(vis, 0, sizeof(vis));
        v.clear(); v.resize(n + 2);
        if (!n && !m) return 0;
        while (m--) {
            int a, b; cin >> a >> b;
            v[a].push_back(b), v[b].push_back(a);
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                chk = 0;
                dfs(i,i);
                if (!chk) res++;
            }
        }
        cout << "Case " << cs << ": ";
        switch (res) {
        case 0:cout << "No trees." << '\n'; break;
        case 1: cout << "There is one tree." << '\n'; break;
        default: cout << "A forest of "<<res<<" trees." << '\n'; break;
        }
    }
}

