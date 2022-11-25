#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;


const int MAXA = 1010, MAXB = 1010;
int A[MAXA], B[MAXB];
bool visited[MAXA];
vector<int> adj[MAXA];
int n, m, k;
bool DFS(int here) {
    if (visited[here]) return false;
    visited[here] = true;
    for (int& there : adj[here])
        if (B[there] == -1 || DFS(B[there])) {
            B[there] = here;
            return true;
        }
    return false;
}
int biMatch(int a) {
    
    int match = 0;
    for (int i = 0; i < MAXA; ++i)
        if (A[i] == -1) {
            memset(visited, 0, sizeof(visited));
            if (DFS(i)) {
                ++match;
                if (a == 2) {
                    k--; if (!k)break;
                }
            }
        }
    return match;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        while (a--) {
            int b; cin >> b;
            adj[i].push_back(b);
        }
    }
    memset(B, -1, sizeof(B));
    memset(A, -1, sizeof(A));
    int res = biMatch(1);
    res += biMatch(1);
    cout << res;
}
/*
5 5 2
3 1 2 3
3 1 2 3
1 5
1 4
1 5
*/