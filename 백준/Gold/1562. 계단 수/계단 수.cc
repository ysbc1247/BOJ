#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

ll a[102][10][4]; ll m = 1e9;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i < 9; i++) {
		a[1][i][0] = 1;
	}
	a[1][9][2] = 1;
	for (int i = 2; i < 102; i++) {
		for (int k = 0; k < 10; k++) {
			if (!k) {
				a[i][k][1] += (a[i - 1][1][0] + a[i - 1][1][1]);
				a[i][k][3] += (a[i - 1][1][2] + a[i - 1][1][3]);
			}
			else if (k == 9) {
				a[i][k][2] += (a[i - 1][8][0] + a[i - 1][8][2]);
				a[i][k][3] += (a[i - 1][8][1] + a[i - 1][8][3]);
			}
			else {
				for (int j = 0; j < 4; j++) { 
					a[i][k][j] += (a[i - 1][k - 1][j] + a[i - 1][k + 1][j]); 
				}
			}
			for (int j = 0; j < 4; j++) {
				a[i][k][j] %= m;
			}
		}
	}
	ll res = 0;
	for (int i = 0; i < 10; i++) {
		res += a[n][i][3]; res %= m;
	}
	cout << res;
}