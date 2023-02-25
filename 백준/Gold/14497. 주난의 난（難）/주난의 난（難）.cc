#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(),v.end();
using namespace std;

char arr[301][301];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
struct st {
    int z, x, y;
};

struct comp {
    bool operator()(st& a, st& b) {
        return a.z < b.z;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int x, y, a, b; cin >> x >> y >> a >> b;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int k = 0; k < m; k++) {
            arr[i][k] = s[k];
        }
    }
    vector<vector<int>>v(n + 1, vector<int>(m + 1, 1e9));
    v[x-1][y-1] = 0;
    priority_queue<st, vector<st>, comp>pq;
    pq.push({ 0,x - 1,y - 1 });
    while (!pq.empty()) {
        int tx = pq.top().x, ty = pq.top().y, tz = -pq.top().z;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int tmpx = tx + dx[i], tmpy = ty + dy[i];
            if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < m) {
                if (arr[tmpx][tmpy] == '1') {
                    if (v[tmpx][tmpy] > tz + 1) {
                        v[tmpx][tmpy] = tz + 1;
                        pq.push({ -tz - 1,tmpx,tmpy });
                    }
                }
                else if (arr[tmpx][tmpy] == '0') {
                    if (v[tmpx][tmpy] > tz) {
                        v[tmpx][tmpy] = tz;
                        pq.push({ -tz,tmpx,tmpy });
                    }
                }
                else {
                    if (tz < v[tmpx][tmpy]) {
                        v[tmpx][tmpy] = tz;
                    }
                }
            }
        }
    }
    cout << v[a-1][b-1] + 1;
}

