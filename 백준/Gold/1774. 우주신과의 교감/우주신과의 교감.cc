#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

struct st {
    double a, b, c;
};
vector<st>V;
double p[100002], res;
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
    vector<pair<double, double>>vv(v);
    for (int i = 0; i < v; i++) {
        cin >> vv[i].first >> vv[i].second;
    }
    for (double i = 0; i < v - 1; i++) {
        for (double k = i + 1; k < v; k++) {
            V.push_back({ i,k,abs(sqrt(pow(vv[i].first - vv[k].first,2) + pow(vv[i].second - vv[k].second,2))) });
        }
    }
    sort(all(V), comp);
    for (int i = 0; i < e; i++) {
        int a, b; cin >> a >> b;
        merge(a - 1, b - 1);
    }
    for (int i = 0; i < (v*(v-1))/2; i++) {
        merge(V[i].a, V[i].b);
        if (chk) {
            res += V[i].c;
        }
    }
    cout << fixed;
    cout << setprecision(2) << res;
}
