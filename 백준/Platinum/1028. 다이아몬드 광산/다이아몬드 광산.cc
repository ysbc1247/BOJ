#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using ll = long long;
using namespace std;

int n, m, D[755][755][2];
int res;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int k = 1; k <= m; k++) {
			D[i][k][0] = D[i][k][1] = s[k-1] - '0';
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int k = 1; k <= m; k++) {
			D[i][k][0] *= 1 + D[i + 1][k + 1][0];
			D[i][k][1] *= 1 + D[i + 1][k - 1][1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int t = D[i][j][1] - 1; t >= res; t--)
				if (D[i][j][0] >= t + 1 && D[i + t][j - t][0] >= t + 1 && D[i + t][j + t][1] >= t + 1)
					res = t + 1;
		}
	}
	cout << res;
}