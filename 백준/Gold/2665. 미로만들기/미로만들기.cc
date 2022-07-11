#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
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

mkxy;
int n;
inline bool chk(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < n) {
		return 1;
	}
	return 0;
}
int main() {
	fastio;
	cin >> n;
	string s;
	int arr[51][51] = {};
	vector<vector<vector<pair<pii, int>>>>v(n + 2);
	rep(i, n + 1) {
		v[i].resize(n + 1);
	}
	rep(i, n) {
		cin >> s;
		rep(k, n) {
			rep(j, 4) {
				int x = i + dx[j], y = k + dy[j];
				if (chk(x, y)) {
					if (s[k] == '1') {
						v[x][y].push_back({ {i,k},0 });
					}
					else {
						v[x][y].push_back({ {i,k},1 });
					}
				}
			}
		}
	}
	int res[51][51] = {};
	rep(i, n) {
		rep(k, n) {
			res[i][k] = 1e9;
		}
	}
	res[0][0] = 0;
	pq<pair<int, pii>>q;
	q.push({ 0, { 0,0 } });
	while (!q.empty()) {
		int now = -q.top().fs;
		int x = q.top().sc.fs, y = q.top().sc.sc;
		q.pop();
		rep(i, v[x][y].size()) {
			int dis = now + v[x][y][i].sc;
			if (dis < res[v[x][y][i].fs.fs][v[x][y][i].fs.sc]) {
				q.push({ -dis,{v[x][y][i].fs.fs,v[x][y][i].fs.sc} });
				res[v[x][y][i].fs.fs][v[x][y][i].fs.sc] = dis;
			}
		}
	}
	cout << res[n - 1][n - 1];
}	
	


	
	