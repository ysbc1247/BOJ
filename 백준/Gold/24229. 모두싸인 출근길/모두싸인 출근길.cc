#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
using ll = long long;

vector<pair<int, int>> v;
vector<pair<int, int>>ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(all(v));
	int a = 0, b = v[0].second;
	for (int i = 1; i < n; i++) {
		if (b >= v[i].first) {
			b = max(b, v[i].second);
		}
		else {
			ans.push_back({ a,b });
			a = v[i].first; b = v[i].second;
		}
	}
	ans.push_back({ a,b });
	a = 0; b = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (b >= ans[i].first) {
			a = i;
			b = max(b, ans[i].second + ans[i].second - ans[i].first);
		}
	}
	cout << ans[a].second;
	return 0;
}