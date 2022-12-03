#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<int>v(8);
    for (int i = 0; i < 8; i++) {
        cin >> v[i];
    }
    if (n * m == 2) {
        cout << "ChongChong"; return 0;
    }
    if (n * m == 5) {
        if (v[0] == v[8]) {
            cout << "ChongChong"; return 0;
        }
    }
    cout << "GomGom";
}