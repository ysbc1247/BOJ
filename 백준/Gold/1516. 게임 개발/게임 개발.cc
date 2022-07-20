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

int n; int sz[501];
int arr[501];
int dp[501];
vector<vector<int>>v;


void ts() {
	queue<int>q;
	rep(i, n) {
		if (!arr[i]) {
			q.push(i); dp[i] = sz[i];
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		rep(i, v[tmp].size()) {
			int nxt = v[tmp][i];
			if (--arr[nxt] == 0) {
				q.push(nxt);
			}
			dp[nxt] = max(dp[nxt], sz[nxt] + dp[tmp]);
		}
	}
	rep(i, n) {
		cout << dp[i] << endl;
	}
}
int main() {
	fastio;
	cin >> n;
	v.resize(n);
	rep(i, n) {
		cin >> sz[i];
		while (1) {
			int a; cin >> a;
			if (a == -1) {
				break;
			}
			v[a - 1].push_back(i);
			arr[i]++;
		}
	}
	ts();
}