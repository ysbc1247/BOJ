#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;

int cap[52][52], flow[52][52];

int mxf(int t, int s) {
    int tot = 0;
    while (1) {
        vector<int>par(52, -1);
        queue<int>q;
        par[t] = t;
        q.push(t);
        while (!q.empty() && par[s] == -1) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < 52; i++) {
                if (cap[now][i] - flow[now][i] > 0 && par[i] == -1) {
                    q.push(i); par[i] = now;
                }
            }
        }
        if (par[s] == -1) break;
        int next = 1e9;
        for (int i = s; i != t; i = par[i]) {
            next = min(cap[par[i]][i] - flow[par[i]][i], next);
        }
        for (int i = s; i != t; i = par[i]) {
            flow[par[i]][i] += next;
            flow[i][par[i]] -= next;
        }
        tot += next;
    }
    return tot;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n; cin >> n;
    char a, b;
    int c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a > 90) {
            a -= 'a'; a += 26;
        }
        else a -= 'A';
        if (b > 90) {
            b -= 'a'; b += 26;
        }
        else b -= 'A';
        cap[a][b] += c; cap[b][a] += c;
    }
    cout << mxf(0, 25);
}