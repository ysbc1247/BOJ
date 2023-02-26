#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;


struct st {
    int a, b;
};
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r;
    cin >> n >> l >> r;
    int arr[102][102] = {};
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> arr[i][k];
        }
    }
    int cnt = 0;
    while (1) {
        bool d = 0;
        bool vis[102][102] = {};
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!vis[i][k]) {
                    queue<st>q;
                    q.push({ i,k });
                    vector<st>v;
                    v.push_back({ i,k });
                    vis[i][k] = 1;
                    while (!q.empty()) {
                        st a = q.front(); q.pop();
                        for (int j = 0; j < 4; j++) {
                            int tmpx = a.a + dx[j], tmpy = a.b + dy[j];
                            if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n) {
                                if (!vis[tmpx][tmpy]) {
                                    if (abs(arr[tmpx][tmpy] - arr[a.a][a.b]) >= l && abs(arr[tmpx][tmpy] - arr[a.a][a.b]) <= r) {
                                        v.push_back({ tmpx,tmpy });
                                        q.push({ tmpx,tmpy });
                                        vis[tmpx][tmpy] = 1;
                                        if (!d) d = 1;
                                    }
                                }
                            }
                        }
                    }
                    int tmp = 0;
                    for (auto w : v) tmp += arr[w.a][w.b];
                    int div = tmp / v.size();
                    for (auto w : v) {
                        arr[w.a][w.b] = div;
                    }
                }
            }
        }
        if (d)cnt++;
        else break;
    }
    cout << cnt;
}

