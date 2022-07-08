#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;


int main(){
    fastio;
    int n,q;
    cin>>n>>q;
    bool res = 0;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        int tmp = c-b;
        if(a==1){
            if(res){
                cout<<0<<endl;
                res = 0;
            }
            else{
                cout<<1<<endl; res = 1;
            }
        }
        else{
            tmp++;
            tmp/=2;
            if(tmp%=2){
                if(res){
                    cout<<0<<endl;
                    res = 0;
                }
                else{
                    cout<<1<<endl; res = 1;
                }
            }
            else{
                cout<<res<<endl;
            }
        }
    }
}
