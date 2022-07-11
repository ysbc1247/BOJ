#include <bits/stdc++.h>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int kmp[1000000];

int main() {
    fastio;
    string s;
    while (1) {
        cin >> s;
        if (s == ".") {
            return 0;
        }
        int temp = s.size();
        memset(kmp, 0, sizeof(kmp));
        for (int i = 1, k = 0; i < temp; i++) {
            while (k && s[i] != s[k]) {
                k = kmp[k - 1];
            }
            if (s[i] == s[k]) {
                kmp[i] = ++k;
            }
        }
        if (temp % (temp - kmp[temp - 1])) {
            cout << 1 << endl;
        }
        else {
            cout << temp / (temp - kmp[temp - 1]) << endl;
        }

    }

}
