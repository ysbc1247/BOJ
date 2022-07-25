#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define pq priority_queue
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;


int main() {
    fastio;
    // clock_t start = clock();
    int n, s; cin >> n >> s;
    vector<int>x(n + 1), h(n + 1);
    rep(i, n) {
        cin >> x[i + 1];
    }
    rep(i, n) {
        cin >> h[i + 1];
    }
    vector<int>res;
    res.push_back(s);
    bool visited[1000005] = {};
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int tmp = x[q.front()]; int r = h[q.front()]; int rem = q.front();  q.pop();
        int high = n;
        int low = rem;
        int mid;
        while (1) {
            if (tmp + r >= x[n]) {
                mid = n; break;
            }
            mid = (low+high) / 2;
            if (x[mid] > tmp + r) {
                high = mid;
            }
            else if (x[mid] < tmp + r) {
                low = mid;
            }
            else if (x[mid] == tmp + r) {
                break;
            }
            if (low + 1 == high || low == high) {
                mid = low; break;
            }
        }
        for (int i = rem + 1; i <= mid; i++) {
            if (!visited[i]) {
                res.push_back(i); q.push(i); visited[i] = 1;
            }
        }
        low = 1; high = rem;
        while (1) {
            if (tmp - r <= x[1]) {
                mid = 1; break;
            }
            mid = (low + high) / 2;
            if (x[mid] > tmp - r) {
                high = mid;
            }
            else if (x[mid] < tmp - r) {
                low = mid;
            }
            else if (x[mid] == tmp - r) {
                break;
            }
            if (low + 1 == high || low == high) {
                mid = high; break;
            }
        }
        for (int i = mid; i < rem; i++) {
            if (!visited[i]) {
                res.push_back(i); q.push(i); visited[i] = 1;
            }
        }
    }
    sort(all(res));
    for (auto i : res) {
        cout << i << ' ';
    }
    // cout<<(double)(clock()-start)/CLOCKS_PER)SEC<<endl;
}