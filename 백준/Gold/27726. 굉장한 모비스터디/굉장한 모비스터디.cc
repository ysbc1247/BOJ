#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;


struct st {
    int a, b, c, d;
};
int p[100005];
int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    p[y] = x;
}
bool comp(const st& a, const st& b) {
    if (a.a == b.a) {
        if (a.b == b.b) {
            if (a.c == b.c) {
                return a.d < b.d;
            }
            else return a.c < b.c;
        }
        else return a.b < b.b;
    }
    else return a.a < b.a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<st>v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i].d = i;
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int a, b, c; cin >> a >> b >> c;
    for (int i = 0; i < a; i++) {
        int q, w; cin >> q >> w;
        merge(q, w);
    }
    for (int i = 1; i <= n; i++) {
        v[i].a = find(i);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < b; i++) {
        int q, w; cin >> q >> w;
        merge(q, w);
    }
    for (int i = 1; i <= n; i++) {
        v[i].b = find(i);
    }
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < c; i++) {
        int q, w; cin >> q >> w;
        merge(q, w);
    }
    for (int i = 1; i <= n; i++) {
        v[i].c = find(i);
    }
    sort(all(v), comp);
    v.erase(v.begin());
    vector<vector<int>>res;
    for (int i = 0; i < n; i++) {
        vector<int>now;
        now.push_back(v[i].d);
        for (int k = i + 1; k < n; k++) {
            if (v[i].b == v[k].b && v[i].c == v[k].c && v[i].a == v[k].a) {
                now.push_back(v[k].d);
                if (k == n - 1) {
                    res.push_back(now);
                    i = n + 1; break;
                }
            }
            else {
                if (now.size() > 1) {
                    sort(all(now));
                    res.push_back(now);
                }
                i = k - 1; break;
            }
        }
    }
    if (res.size() == 0) {
        cout << 0; return 0;
    }
    cout << res.size() << '\n';
    sort(all(res));
    for (auto i : res) {
        sort(all(i));
        for (auto k : i) {
            
            cout << k;
            if (k != i.back()) cout << ' ';
        }
        if(i!=res.back())
        cout << '\n';
    }
}
