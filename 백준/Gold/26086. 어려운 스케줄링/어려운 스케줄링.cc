#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int>d;
    int n, q, k; cin >> n >> q >> k;
    int lst = 0;
    int cnt = 0;
    int l = -1;
    vector<pair<int, int>>v;
    for (int i = 0; i < q; i++){
        int a; cin >> a;
        if (a == 1) {
            l = i;
            v.push_back({ 1,0 });
        }
        if (!a) {
            int b; cin >> b;
            v.push_back({ 0,b });
        }
        if (a == 2) {
            v.push_back({ 2,0 });
        }
    }
    for (int i = 0; i < l; i++) {
        if (v[i].first == 0) {
            d.push_back(v[i].second);
        }
    }
    
    sort(all(d));
    for (int i = l + 1; i < q; i++) {
        if (v[i].first == 0) {
            if (cnt % 2 == 0) {
                d.push_front(v[i].second);
            }
            else {
                d.push_back(v[i].second);
            }
        }
        else {
            cnt++;
        }
    }
    if (cnt % 2 == 0) {
        cout << d[k - 1];
    }
    else cout << d[d.size() - k];
}