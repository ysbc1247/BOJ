#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

int n; vector<int>v[200002];
int arr[200002];
bool vis[200002];

void dfs(int a, int b) {
	vis[a] = 1;
	for (auto i : v[a]) {
		if (arr[i] == b && !vis[i]) {
			dfs(i, b);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && arr[i]!=0) {
			cnt++;
			dfs(i, arr[i]);
		}
	}
	cout << cnt;
}