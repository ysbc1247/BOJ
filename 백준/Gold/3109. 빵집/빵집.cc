#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()
int r, c;
char arr[10005][505];
int cnt = 0;
bool ret = 0;
bool chk[10005][505];
int dx[3]={-1,0,1},dy[3]={1,1,1};

void dfs(int x, int y){
    if(ret)return;
    chk[x][y] = 1;
    if(y==c-1){
        ret = 1; cnt++; return;
    }
    for(int k=0; k<3; k++){
        int tmpx = x+dx[k],tmpy = y+dy[k];
        if(tmpx>=0&&tmpx<r&&tmpy>=0&&tmpy<c){
            if(arr[tmpx][tmpy]=='.'){
                if(!chk[tmpx][tmpy]){
                    dfs(tmpx,tmpy);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>r>>c;
    for(int i=0; i<r; i++){
        for(int k=0; k<c; k++){
            cin>>arr[i][k];
        }
    }
    for(int i=0; i<r; i++){
        ret = 0;
        dfs(i,0);
    }
    cout<<cnt;
}

