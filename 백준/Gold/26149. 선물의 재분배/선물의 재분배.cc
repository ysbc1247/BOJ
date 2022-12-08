#include <bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end()
using namespace std;
using ii = pair<int, int>;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int>a(n),b(n),c(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int mx = max_element(all(b)) - b.begin();
    a[mx] = 0;
    sort(a.rbegin(),a.rend());
    vector<ii> v;
    for (int i = 0; i < n; ++i) {
        if (a[i]) {
            v.push_back({mx + 1, a[i]});
        }
    }
    for (int i = 0; i < n; ++i) {
        if (mx == i || b[i] == 0) {
            continue;
        }
        v.push_back({i + 1, b[i]});
    }
    cout << v.size() << '\n';
    for (auto p : v) {
        cout << "+ " << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
