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


int main() {
	fastio;
	int dp[100005] = {};
	int n; cin >> n; int k; cin >> k;
	vector<int>v(n);
	rep(i, k + 1) {
		dp[i] = 1e9;
	}
	rep(i, n) {
		cin >> v[i];
		dp[v[i]] = 1;
	}
	rep(i, k+1) {
		rep(k, v.size()) {
			if (i - v[k] > 0) {
				dp[i] = min(dp[i], 1 + dp[i - v[k]]);
			}
		}
	}
	if (dp[k] == 1e9) {
		cout << -1; return 0;
	}
	cout << dp[k];
}