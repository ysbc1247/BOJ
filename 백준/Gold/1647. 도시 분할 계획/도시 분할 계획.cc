#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

struct st {
    int a, b, c;
};
vector<st>V;
int p[100002], res;
bool chk;
bool comp(st a, st b) {
    return a.c < b.c;
}
int find(int a) {
    if (a == p[a]) {
        return a;
    }
    return p[a] = find(p[a]);
}
void merge(int a, int b) {
    chk = 0;
    a = find(a); b = find(b);
    if (a == b) return;
    p[a] = b;
    chk = 1;
}
int mx = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e; cin >> v >> e;
    for (int i = 0; i <= v; i++) {
        p[i] = i;
    }
    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        V.push_back({ a,b,c });
    }
    sort(all(V), comp);
    for (int i = 0; i < e; i++) {
        merge(V[i].a, V[i].b);
        if (chk) {
            res += V[i].c;
            mx = max(V[i].c, mx);
        }
    }
    cout << res - mx;
}
