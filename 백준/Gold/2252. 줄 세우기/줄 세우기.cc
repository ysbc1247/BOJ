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
int arr[32005];

void ts() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (!arr[i]) {
			q.push(i); cout << i << endl;
		}
	}
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		rep(i, v[tmp].size()) {
			int nxt = v[tmp][i];
			if (--arr[nxt] == 0) {
				q.push(nxt); cout << nxt << endl;
			}
		}
	}
}
int main() {
	fastio;
	cin >> n >> m; v.resize(n + 1);
	rep(i, m) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		arr[b]++;
	}
	ts();

}