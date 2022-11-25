#include<bits/stdc++.h>
using ll = long long;
#define all(v)  v.begin(), v.end()
using namespace std;

string s;
int res = 1e9;
void dfs(int a, int b, int c) {
	if (c > 3) return;
	if (a >= b) {
		res = min(res, c); return;
	}
	if (s[a] == s[b]) {
		dfs(a + 1, b - 1, c);
	}
	else {
		dfs(a, b - 1, c + 1);
		dfs(a + 1, b, c + 1);
	}
}
int main() {
	 cin >> s;
	 dfs(0, s.size() - 1, 0);
	 if (res == 1e9) cout << -1;
	 else cout << res;
}