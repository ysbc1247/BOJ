#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()
 
int n,m,K;
int arr[1001][1001];
int sm[1001][1001][4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>K;
    for(int i=0; i<n; i++){
        for(int k=0; k<m; k++){
            char a; cin>>a;
            if(a=='J'){
                arr[i][k] = 0;
            }
            else if(a=='O'){
                arr[i][k] = 1;
            }
            else{
                arr[i][k] = 2;
            }
        }
    }
    sm[0][0][arr[0][0]]=1;
    for(int i=1; i<n; i++){
        for(int k=0; k<3; k++){
            sm[i][0][k] = sm[i-1][0][k];
        }
        sm[i][0][arr[i][0]]++;
    }
    for(int i=1; i<m; i++){
        for(int k=0; k<3; k++){
            sm[0][i][k] = sm[0][i-1][k];
        }
        sm[0][i][arr[0][i]]++;
    }
    for(int i=1; i<n; i++){
        for(int k=1; k<m; k++){
            for(int j=0; j<4; j++){
                sm[i][k][j]+=sm[i-1][k][j]+sm[i][k-1][j]-sm[i-1][k-1][j];
            }
            sm[i][k][arr[i][k]]++;
        }
    }
    while(K--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;b--;c--;d--;
        for(int i=0; i<3 ;i++){
            int tmp = sm[c][d][i];
            if(a){
                tmp-=sm[a-1][d][i];
            }
            if(b){
                tmp-=sm[c][b-1][i];
            }
            if(a&&b){
                tmp+=sm[a-1][b-1][i];
            }
            cout<<tmp<<' ';
        }
        cout<<'\n';
    }
}
