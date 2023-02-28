#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;


struct st {
    int a, b;
};
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char arr[51][51];
int vis[51][51];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int r, c; cin >> r >> c;
    queue<st>q;
    queue<st>w;
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            cin >> arr[i][k];
            if (arr[i][k] == 'S') {
                vis[i][k] = 1;
                q.push({ i,k });
            }
            else if (arr[i][k] == '*') {
                vis[i][k] = 1;
                w.push({ i,k });
            }
        }
    }
    int cnt = 0;
    bool chk = 0;
    while (1) {
        
        cnt++;
        int wc = w.size(), qc = q.size();
        if (!wc && !qc) break;
        for(int k=0; k<wc; k++){
            st now = w.front(); w.pop();
            for (int i = 0; i < 4; i++) {
                int tmpx = now.a + dx[i], tmpy = now.b + dy[i];
                if (tmpx >= 0 && tmpx < r && tmpy >= 0 && tmpy < c) {
                    if (!vis[tmpx][tmpy]&&arr[tmpx][tmpy]!='D') {
                        vis[tmpx][tmpy] = cnt;
                        if (arr[tmpx][tmpy] != 'X') {
                            w.push({ tmpx,tmpy });
                        }
                    }
                }
            }
        }
        for(int k=0; k<qc; k++){
            st now = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int tmpx = now.a + dx[i], tmpy = now.b + dy[i];
                if (tmpx >= 0 && tmpx < r && tmpy >= 0 && tmpy < c) {
                    if (vis[tmpx][tmpy] == cnt && arr[tmpx][tmpy] == 'D') {
                        cout << cnt; return 0;
                    }
                    if (!vis[tmpx][tmpy]) {
                        vis[tmpx][tmpy] = cnt;
                        if (arr[tmpx][tmpy] != 'X') {
                            q.push({ tmpx,tmpy });
                        }
                        if (arr[tmpx][tmpy] == 'D') {
                            cout << cnt; return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "KAKTUS";
}

