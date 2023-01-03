#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

ll n, k;
vector<pair<ll,ll>>v;
vector<ll>bag;
priority_queue<ll,vector<ll>,less<ll>>pq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(all(v));
    bag.resize(k);
    for(int i=0; i<k; i++){
        cin>>bag[i];
    }
    sort(all(bag));
    ll ix = 0;
    ll res = 0;
    for (int i = 0; i < k; i++) {
            while (ix < n && bag[i] >= v[ix].first) {
                pq.push(v[ix].second);
                ix++;
            }
            if (!pq.empty()) {
                res += pq.top();
                pq.pop();
            }
    }
    cout<<res;
}

