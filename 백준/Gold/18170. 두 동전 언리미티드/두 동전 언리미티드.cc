#include<bits/stdc++.h>
using ll = long long;
#define all(v) v.begin(), v.end()
using namespace std;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
struct st{
    int a, b,c,d;
};
int n,m;
bool chk(int a, int b){
    if(a>=n||a<0||b>=m||b<0){
        return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    char arr[21][21]={};
    bool vis[21][21][21][21]={};
    queue<st>q;
    int a = -1,b,c,d;
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            cin>>arr[i][k];
            if(arr[i][k]=='o'){
                if(a==-1){
                    a = i, b = k;
                }
                else c = i, d = k;
            }
        }
    }
    q.push({a,b,c,d});
    vis[a][b][c][d] = 1;
    int cnt= 0;
    while(!q.empty()){
        int tmp = q.size();
        for(int w = 0; w<tmp; w++){
            a = q.front().a, b = q.front().b, c = q.front().c, d = q.front().d;
            q.pop();
            vis[a][b][c][d] = 1;
            for(int i=0; i<4; i++){
                int ta = a+dx[i], tb = b+dy[i], tc = c+dx[i], td = d+dy[i];
                if((chk(ta,tb)&&!chk(tc,td))||(!chk(ta,tb)&&chk(tc,td))){
                    cout<<cnt+1; return 0;
                }
                else if(!chk(ta,tb)&&!chk(tc,td)){
                    if(arr[ta][tb]=='#'){
                        ta = a, tb = b;
                    }
                    if(arr[tc][td]=='#'){
                        tc = c, td = d;
                    }
                    if(!vis[ta][tb][tc][td]){
                        q.push({ta,tb,tc,td});
                    }
                }
            }
        }
        cnt++;
    }
    cout<<-1;
}
