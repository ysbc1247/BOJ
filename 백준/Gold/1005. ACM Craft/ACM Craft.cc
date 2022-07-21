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

int n, m;
vector<vector<int>>v;
int arr[1005];
int sv[1005];
int dp[1005];
void ts() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			q.push(i); dp[i] = sv[i];
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
			dp[nxt] = max(dp[nxt], dp[tmp] + sv[nxt]);
		}
	}
}
int main() {
	fastio;
	int t; cin >> t;
	while (t--) {
		v.clear(); ms(arr, 0); ms(sv, 0); ms(dp, 0);
		cin >> n >> m; v.resize(n + 1);
		rep(i, n) {
			cin >> sv[i + 1];
		}
	
		rep(i, m) {
			int a, b; cin >> a >> b;
			v[a].push_back(b);
			arr[b]++;
		}
		ts();
		int w; cin >> w;
		cout << dp[w] << endl;
	}
}