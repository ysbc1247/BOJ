#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;


int p[4000001];

int f(int x) {
    if (p[x] == x) return p[x];

    return f(p[x]);
}

void merge(int x, int y) {
    int xp = f(x);
    int yp = f(y);

    if (xp < yp) p[xp] = yp;
    else p[yp] = xp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(all(v));
    for (int i = 0; i < m; i++) p[i] = i;

    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        int ix = lower_bound(v.begin(), v.end(), tmp+1) - v.begin();
        cout << v[f(ix)] << '\n';
        if (ix <= m-1) merge(f(ix), f(ix) + 1);
    }
}
