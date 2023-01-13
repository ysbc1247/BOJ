#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

vector<int>vis(100060);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    map<int,int>q;
    q[n] = 1;
    bool res = 0;
    int cnt =  0;
    vis[n] = 1;
    while(1){
        if(q.find(k)!=q.end()){
            cout<<cnt<<'\n';
            cout<<q[k]; return 0;
        }
        if(res)break;
        cnt++;
        map<int,int>m2;
        int c2 = 0;
        int tmp = q.size();
        set<int>s;
        for(auto i:q){
            if(c2==tmp)break;
            c2++;
            if(i.first+1<=100050){
                if(!vis[i.first+1]){
                    
                    m2[i.first+1]+=i.second;
                    s.insert(i.first+1);
                }
            }
            if(i.first-1>=0){
                if(!vis[i.first-1]){
                    m2[i.first-1]+=i.second;
                    s.insert(i.first-1);
                }
                
            }
            if(i.first*2<=100050){
                if(!vis[i.first*2]){
                    
                    m2[i.first*2]+=i.second;
                    s.insert(i.first*2);
                }
            }
        }
        for(auto w:s){
            vis[w]=1;
        }
        q = m2;
    }
}

