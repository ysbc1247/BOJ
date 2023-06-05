#include<bits/stdc++.h>
using namespace std;
int w,b,q,r,c,cn,cx[9]={0,0,0,1,1,2,3,5,11},dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1},vs[4][4];char u[4][4];string rs,n;vector<string> v;bool cmp(string a,string b){if(a.size()==b.size()) return a>b;return a.size()<b.size();}
void dfs(int a,int x,int y){if(q)return;for(int i=0;i<8;i++){int tx=x+dx[i],ty=y+dy[i];if(tx>=0&&tx<4&&ty>=0&&ty<4&&!vs[tx][ty]&&n[a]==u[tx][ty]){if(a==n.size()-1){q=1;cn++;rs=n;r+=cx[a+1];return;}vs[tx][ty]=1;dfs(a+1,tx,ty);vs[tx][ty]=0;if(q)return;}}vs[x][y]=0;}
int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>w;v.resize(w);for(int i=0;i<w;i++)cin>>v[i];sort(v.begin(),v.end(),cmp);cin>>b;while(b--){for(int i=0;i<4;i++)for(int k=0;k<4;k++)cin>>u[i][k];cn=0;rs="Z";r=0;for(auto i:v){q=0;n=i;for(int k=0;k<4;k++){for(int j=0;j<4;j++){if(u[k][j]==i[0]){if(i.size()==1){q=1;cn++;rs=i;break;}memset(vs,0,sizeof(vs));vs[k][j]=1;dfs(1,k,j);}if(q)break;}if(q)break;}}cout<<r<<' '<<rs<<' '<<cn<<'\n';}}
