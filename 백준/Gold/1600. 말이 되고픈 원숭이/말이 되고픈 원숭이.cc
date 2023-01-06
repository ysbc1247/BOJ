#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int K,w,h;
int arr[202][202];
int chk[202][202][31];
struct st{
    int x,y,k;
};
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int x2[8]={-2,-2,-1,-1,1,1,2,2},y2[8]={-1,1,-2,2,-2,2,-1,1};
int mx = 1e9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>K>>h>>w;
    for(int i=0; i<w; i++){
        for(int k=0; k<h; k++){
            cin>>arr[i][k];
        }
    }
    queue<st>q;
    q.push({0,0,0});
    int cnt = 0;
    bool ret = 0;
    while(!q.empty()){
        int tmp = q.size();
        if(ret) break;
        for(int a=0; a<tmp; a++){
            st now = q.front();q.pop();
            if(now.x==w-1&&now.y==h-1){
                mx = cnt;
                ret = 1;
                break;
            }
            for(int i=0; i<4; i++){
                int tmpx = now.x+dx[i],tmpy = now.y+dy[i];
                if(tmpx>=0&&tmpx<w&&tmpy>=0&&tmpy<h){
                    if(arr[tmpx][tmpy]==0){
                        if(!chk[tmpx][tmpy][now.k]){
                            q.push({tmpx,tmpy,now.k});
                            chk[tmpx][tmpy][now.k] = 1;
                        }
                    }
                }
            }
            if(now.k<K){
                for(int i=0; i<8; i++){
                    int tmpx = now.x+x2[i],tmpy = now.y+y2[i];
                    if(tmpx>=0&&tmpx<w&&tmpy>=0&&tmpy<h){
                        if(arr[tmpx][tmpy]==0){
                            if(!chk[tmpx][tmpy][now.k+1]){
                                q.push({tmpx,tmpy,now.k+1});
                                chk[tmpx][tmpy][now.k+1] = 1;
                            }
                        }
                    }
                }
            }
        }
        cnt++;
    }
    if(mx==1e9)cout<<-1;
    else cout<<mx;
}

