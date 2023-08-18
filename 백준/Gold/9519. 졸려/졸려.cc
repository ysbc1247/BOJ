#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

void solve() {
    int n; string s;
    cin >> n >> s;
    string q = s;
    int cnt = 0;
    while (1) {
        cnt++;
        for (int i = (q.size() % 2 ? q.size() - 2 : q.size() - 1); i >= 1; i -= 2) {
            char c = q[i];
            q.erase(q.begin() + i);
            q += c;
        }
        if (q == s) {
            break;
        }
    }
    n %= cnt;
    while (n--) {
        for (int i = (s.size()%2?s.size()-2:s.size() - 1); i >= 1; i -= 2) {
            char c = s[i];
            s.erase(s.begin() + i);
            s += c;
        }
    }
    cout << s;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1; 
    while (t--) {
        solve();
    }
}