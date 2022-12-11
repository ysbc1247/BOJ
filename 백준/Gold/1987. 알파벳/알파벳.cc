#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int mx = 0; int r, c;
int dx[4] = { 1,-1,0,0 }; int dy[4] = { 0,0,1,-1 };
char arr[21][21];
bool visited[26];
void dfs(int a, int b, int cnt) {
    mx = max(cnt, mx);
    for (int i = 0; i < 4; i++) {
        int tmpx = a + dx[i], tmpy = b + dy[i];
        if (tmpx >= 0 && tmpx < r && tmpy >= 0 && tmpy < c) {
            if (!visited[arr[tmpx][tmpy] - 'A']) {
                visited[arr[tmpx][tmpy] - 'A'] = 1;
                dfs(tmpx, tmpy, cnt + 1);
                visited[arr[tmpx][tmpy] - 'A'] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int k = 0; k < c; k++) {
            cin >> arr[i][k];
        }
    }
    visited[arr[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << mx;
}