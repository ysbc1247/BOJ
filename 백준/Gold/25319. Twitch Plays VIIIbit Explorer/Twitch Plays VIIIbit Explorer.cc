#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define ll long long
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;

int n, m;
char arr[51][51]; string s1;
vector<vector<pii>>v;
int main() {
    fastio;
    int q;
    cin >> n >> m >> q;
    v.resize(26);
    for (int i = 0; i < n; i++) {
        cin >> s1;
        for (int k = 0; k < m; k++) {
            arr[i][k] = s1[k];
            v[s1[k] - 'a'].push_back({ i,k });
        }
    }
    string s; cin >> s;
    vector<char>res;
    int ptmp = 0;
    int x = 0, y = 0;
    int tmp = 0;
    int restmp = 0;
    while (1) {
        if (tmp == s.size()) {
            restmp++;
            tmp = 0;
        }
        char c = s[tmp];
        if (v[c - 'a'].size() == 0) {
            if (ptmp % s.size()) {
                int t = ptmp%s.size();
                int tt = 0;
                for (int i = res.size() - 1; i >= 0; i--) {
                    if (res[i] == 'P') {
                        tt++;
                    }
                    switch(res[i]){
                        case 'D': x--; break;
                        case 'L': y++; break;
                        case 'R': y--; break;
                        case 'U': x++; break;
                        case 'P': break;
                    }
                    res.pop_back();
                    if (tt == t) {
                        break;
                    }
                }
            }
            int aa = n - x - 1, bb = m - y - 1;
            for (int i = 0; i < aa; i++) {
                res.push_back('D');
            }
            for (int i = 0; i < bb; i++) {
                res.push_back('R');
            }
            cout << restmp << ' ' << res.size() << endl;
            for (int i = 0; i < res.size(); i++) {
                cout << res[i];
            }
            return 0;
        }
        int tmpx = v[c - 'a'][v[c - 'a'].size() - 1].fs;
        int tmpy = v[c - 'a'][v[c - 'a'].size() - 1].sc;
        int up = tmpx - x;
        if (up > 0) {
            for (int i = 0; i < up; i++) {
                res.push_back('D');
            }
        }
        else {
            for (int i = 0; i < -up; i++) {
                res.push_back('U');
            }
        }
        int down = tmpy - y;
        if (down > 0) {
            for (int i = 0; i < down; i++) {
                res.push_back('R');
            }
        }
        else {
            for (int i = 0; i < -down; i++) {
                res.push_back('L');
            }
        }
        res.push_back('P');
        ptmp++;
        v[c - 'a'].pop_back();
        tmp++;
        x = tmpx; y = tmpy;
    }
}
