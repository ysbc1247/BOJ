#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

struct st{
    int a,b,c,d;
};
int dx[4]={1,-1,0,0}, dy[4] = {0,0,-1,1};
struct comp{
    bool operator()(const st& a, const st& b){
        return a.a<=b.a;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m,sx,sy,ex,ey;
    cin>>n>>m>>sx>>sy>>ex>>ey;
    sx--; sy--; ex--; ey--;
    int arr[102][102]={};
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin>>arr[i][k];
        }
    }
    vector<int>v2(m+2,1e9);
    vector<vector<int>>v1(n+2,v2);
    vector<vector<vector<int>>>v(3,v1);
    priority_queue<st, vector<st>, comp>q;
    q.push({0,sx,sy,1});
    while(!q.empty()){
        int dis = - q.top().a;
        int x = q.top().b, y = q.top().c;
        int cnt = q.top().d;
        q.pop();
        switch(cnt%3){
            case 0:
                for(int i=0; i<4; i++){
                    int tmpx = x+dx[i], tmpy = y+dy[i];
                    if(tmpx>=0&&tmpx<n&&tmpy>=0&&tmpy<m){
                        if(arr[tmpx][tmpy]!=-1){
                            int nxtd = dis + arr[tmpx][tmpy];
                            if(nxtd < v[0][tmpx][tmpy]){
                                v[0][tmpx][tmpy] = nxtd;
                                q.push({-nxtd,tmpx,tmpy,cnt+1});
                            }
                        }
                    }
                }
                break;
            case 1:
                if(x+1<n){
                    if(arr[x+1][y]!=-1){
                        int nxtd = dis+arr[x+1][y];
                        if(nxtd < v[1][x+1][y]){
                            q.push({-nxtd,x+1,y,cnt+1});
                            v[1][x+1][y] = nxtd;
                        }
                    }
                }
                if(x-1>=0){
                    if(arr[x-1][y]!=-1) {
                        int nxtd = dis+arr[x-1][y];
                        if(nxtd < v[1][x-1][y]){
                            q.push({-nxtd, x-1, y, cnt+1});
                            v[1][x-1][y] = nxtd;
                        }
                        
                    }
                }
                break;
            case 2:
                if(y+1<m){
                    if(arr[x][y+1]!=-1){
                        int nxtd = dis+arr[x][y + 1];
                        if(nxtd < v[2][x][y + 1]){
                            q.push({-nxtd,x,y + 1,cnt+1});
                            v[2][x][y+1] = nxtd;
                        }
                    }
                }
                if(y-1>=0){
                    if(arr[x][y-1]!=-1){
                        int nxtd = dis+arr[x][y - 1];
                        if(nxtd < v[2][x][y - 1]){
                            q.push({-nxtd, x, y - 1, cnt+1});
                            v[2][x][y-1] = nxtd;
                        }
                    }
                }
                break;
            default:break;
        }
    }
    int mn  = min({v[0][ex][ey],v[1][ex][ey],v[2][ex][ey]});
    if(mn == 1e9) cout<<-1;
    else cout<<mn;
}
