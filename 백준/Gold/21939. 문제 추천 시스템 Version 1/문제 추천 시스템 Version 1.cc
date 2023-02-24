#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;

int n, p, m, l;
map<int, set<int>>mp;
map<int, int>mm;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> l;
        mm[p] = l;
        mp[l].insert(p);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        if (s == "add") {
            int a, b; cin >> a >> b;
            int tmp = 0;
            if (mm.find(a) != mm.end()) {
                tmp = mm[a];
                mp[tmp].erase(a);
            }
            mm[a] = b;
            mp[b].insert(a);
        }
        if (s == "recommend") {
            int a; cin >> a;
            if (a == 1) {
                for (int i = 100; i >= 0; i--) {
                    if (mp.find(i) != mp.end()) {
                        if (mp[i].size()) {
                            cout << *--mp[i].end() << '\n';
                            break;
                        }
                    }
                }
            }
            else {
                for (int i = 0; i <= 100; i++) {
                    if (mp.find(i) != mp.end()) {
                        if (mp[i].size()) {
                            cout << *mp[i].begin() << '\n';
                            break;
                        }
                    }
                }
            }
        }
        if (s == "solved") {
            int a; cin >> a;
            int tmp = mm[a];
            mm.erase(a);
            mp[tmp].erase(a);
        }
    }
}

