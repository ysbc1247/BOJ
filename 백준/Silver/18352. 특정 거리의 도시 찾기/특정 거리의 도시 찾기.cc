#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
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

int n, m, k, x;
vector<vector<int>>v;
int arr[300005];

void dijk() {
	queue<pii>q;
	q.push({ 0,x });
	while (!q.empty()) {
		int tmp = q.front().sc;
		int dis = -q.front().fs;
		q.pop();
		rep(i, v[tmp].size()) {
			int nxt = v[tmp][i];
			if (dis + 1 < arr[nxt]) {
				q.push({ -dis - 1 ,nxt });
				arr[nxt] = dis + 1;
			}
		}
	}
}
int main() {
	fastio;
	cin >> n >> m >> k >> x;
	v.resize(n + 1);
	rep(i, n + 1) {
		arr[i] = 1e9;
	}
	arr[x] = 0;
	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	bool chk = 0;
	dijk();
	rep(i, n + 1) {
		if (arr[i] == k) {
			cout << i << endl;
			chk = 1;
		}
	}
	if (!chk) {
		cout << -1;
	}
}


