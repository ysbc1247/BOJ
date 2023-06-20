#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
typedef long long ll;
using namespace std;

int n;
vector<vector<pii>>v(10001);
bool visited[10001];
int a, b, c;
int mx;
void solve(int a,int b, bool c) {
	if (v[a].size() == 1 && c) {
		mx = max(mx, b);
		return;
	}
	visited[a] = 1;
	for (int i = 0; i < v[a].size(); i++) {
		if (!visited[v[a][i].first]) {
			solve(v[a][i].first, b + v[a][i].second, 1);
		}
	}
}
int main() {
	fastio;
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() == 1) {
			memset(visited, 0, sizeof(visited));
			solve(i,0,0);
		}
	}
	cout << mx;
}