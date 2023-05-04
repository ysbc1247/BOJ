#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<ll,ll>aa, bb;
    ll a,b;
    cin>>a>>b;
    ll aq = a, bq = b;
    for(int i=2; i*i<=a; i++){
        while(aq%i==0){
            aq/=i;
            aa[i]++;
        }
    }
    if(aq!=1){
        aa[aq]++;
    }
    for(int i=2; i*i<=b; i++){
        while(bq%i==0){
            bq/=i;
            bb[i]++;
        }
    }
    if(bq!=1){
        bb[bq]++;
    }
    int res = 1;
    set<int>chk;
    for(auto i:aa){
        if(chk.find(i.first)==chk.end()){
            chk.insert(i.first);
            if(bb.find(i.first)==bb.end()){
                cout<<0;
                return 0;
            }
            else if (bb[i.first]<i.second){
                cout<<0;return 0;
            }
            else res*=(bb[i.first]-i.second+1);
        }
    }
    for(auto i:bb){
        if(chk.find(i.first)==chk.end()){
            chk.insert(i.first);
            if(aa.find(i.first)!=aa.end()){
                res*=(i.second-aa[i.first] + 1);
            }
            else {
                res*=(i.second+1);
            }
        }
    }
    cout<<res;
}

/*
 2, 4
 2, 4, 6,8,10...
 6, 9
 3, 9,
 2, 5->10
 c-> 2, 10
 gcd * x(x에는 a,b의 인수가 없음) =
 1,2,3 2,3,4 -> 2,3,4 최대 2개, a>b -> 정확히 a만큼, a<b -> b이하 모두 가능.
 */
