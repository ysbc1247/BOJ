#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;
//상하좌우앞뒤 //아래 위 오른쪽 왼쪽
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int x[6][4]={{4,5,3,2},{5,4,2,3},{2,2,0,1},{3,3,1,0},{1,0,4,4},{0,1,5,5}};
struct st{
    int a, b, c;
};
void solve() {
    int n,m;cin>>n>>m;
    bool a[501][501][6]={};
    char b[501][501]={};
    pair<int,int>d,r;
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin>>b[i][k];
            if(b[i][k]=='D') d = {i,k};
            if(b[i][k]=='R') r = {i,k};
        }
    }
    queue<st>q;
    q.push({d.first,d.second,1});
    int res = 0;
    while(!q.empty()){
        int tmp = q.size();
        for(int j = 0; j<tmp ;j++) {
            st s = q.front();
            q.pop();
            if (s.a == r.first && s.b == r.second && s.c == 1) {
                cout << res;
                return;
            }
            for (int i = 0; i < 4; i++) {
                int tx = s.a + dx[i], ty = s.b + dy[i];
                if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                    if (b[tx][ty] != '#') {
                        if (!a[tx][ty][x[s.c][i]]) {
                            if (tx == r.first && ty == r.second && x[s.c][i] != 1) continue;
                            a[tx][ty][x[s.c][i]] = 1;
                            q.push({tx, ty, x[s.c][i]});
                        }
                    }
                }
            }
        }
        res++;
    }
    cout<<-1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
}