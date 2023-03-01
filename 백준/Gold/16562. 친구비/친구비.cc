#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;

int p[10002];
int q[10002];
int n, m, K;
int find(int a) {
    if (a == p[a])return a;
    return p[a] = find(p[a]);
}

void merge(int a, int b) {
    int pa = find(a), pb = find(b);
    if (q[pa] < q[pb]) {
        p[pb] = pa;
    }
    else p[pa] = pb;
}
bool vis[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> K;
    for (int i = 0; i < n; i++) {
        cin >> q[i+1];
    }
    for (int i = 0; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int v, w; cin >> v >> w;
        merge(v, w);
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res += q[find(i)];
            if (res > K) {
                cout << "Oh no"; return 0;
            }
            for (int k = 0; k <= n; k++) {
                if (find(k) == find(i)) {
                    vis[k] = 1;
                }
            }
        }
    }
    cout << res;
}

