#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

int n;
char arr[101][101];
int vis[101][101];
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int res = 0;
void dfs(int a, int b, char c) {
	bool chk = 0;
	vis[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int tmpx = a + dx[i], tmpy = b + dy[i];
		if (tmpx >= 0 && tmpx < n && tmpy >= 0 && tmpy < n) {
			if (!vis[tmpx][tmpy]) {
				if (arr[tmpx][tmpy] == c) {
					dfs(tmpx, tmpy, c);
				}
			}
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> arr[i][k];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (!vis[i][k]) {
				res++;
				dfs(i, k, arr[i][k]);
			}
		}
	}
	cout << res << ' ';
	res = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (arr[i][k] == 'R') {
				arr[i][k] = 'G';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (!vis[i][k]) {
				res++;
				dfs(i, k, arr[i][k]);
			}
		}
	}
	cout << res;
}