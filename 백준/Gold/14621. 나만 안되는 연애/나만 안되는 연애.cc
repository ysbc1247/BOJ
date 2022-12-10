#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

struct st {
    ll a, b, c;
};
vector<st>V;
ll p[200002], res;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int v, e; cin >> v >> e;
    ll mx = 0;
    bool man[1001] = {};
    for (int i = 0; i < v; i++) {
        p[i] = i;
        char a; cin >> a;
        if (a == 'M') {
            man[i] = 1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < e; i++) {
        ll a, b, c; cin >> a >> b >> c;
        if (man[a - 1] == man[b - 1]) {
            cnt++; continue;
        }
        V.push_back({ a-1,b-1,c });
    }
    sort(all(V), comp);
    int tmp = 0;
    for (int i = 0; i < e - cnt; i++) {
        merge(V[i].a, V[i].b);
        if (chk) {
            res += V[i].c; tmp++;
        }
    }
    if (tmp != v-1) {
        cout << -1; return 0;
    }
    cout << res;

}