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
int n, m;
int arr[101][101] = {};
vector<vector<vector<pair<pii, int>>>>v;

inline bool solve(int a, int b) {
	if (a >= 0 && a < n && b >= 0 && b < m) {
		return 1;
	}
	return 0;
}
int main() {
	fastio;
	cin >> m >> n;
	v.resize(n);
	rep(i, n) {
		v[i].resize(m);
	}
	char a;
	rep(i, n) {
		string s; cin >> s;
		rep(k, m) {
			a = s[k];
			if (a=='1') {
				rep(j, 4) {
					int tmpx = i + dx[j]; int tmpy = k + dy[j];
					if (solve(tmpx, tmpy)) {
						v[tmpx][tmpy].push_back({ {i,k},1 });
					}
				}
			}
			else {
				rep(j, 4) {
					int tmpx = i + dx[j]; int tmpy = k + dy[j];
					if (solve(tmpx, tmpy)) {
						v[tmpx][tmpy].push_back({ {i,k},0 });
					}
				}
			}
		}
	}
	pq<pair<int, pii>>q;
	rep(i, n) {
		rep(k, m) {
			arr[i][k] = 1e9;
		}
	}
	arr[0][0] = 0;
	q.push({ 0,{0,0} });
	while (!q.empty()) {
		int dis = -q.top().fs;
		int f = q.top().sc.fs;
		int e = q.top().sc.sc;
		q.pop();
		rep(i, v[f][e].size()) {
			int td = dis + v[f][e][i].sc;
			int tmpx = v[f][e][i].fs.fs;
			int tmpy = v[f][e][i].fs.sc;
			if (td < arr[tmpx][tmpy]) {
				q.push({ -td,{tmpx,tmpy} });
				arr[tmpx][tmpy] = td;
			}
		}
	}
	cout << arr[n - 1][m - 1];
}
	