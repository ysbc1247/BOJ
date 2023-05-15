#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
using ll = long long;
using namespace std;

char arr[500001] = {};
bool comp(int a, int b) {
	return arr[a] > arr[b];
}
bool comp2(pair<int, int>a, pair<int, int>b) {
	return arr[a.first] > arr[b.first];
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	vector<vector<int>>v(n + 1);
	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[i + 1] = s[i];
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	for (int i = 0; i <= n; i++) {
		sort(all(v[i]), comp);
	}
	vector<pair<int,int>>res;
	res.push_back({ 1,0 });
	string ret = "";
	while (1) {
		vector<pair<int,int>>nxt;
		if (!res.size()) break;
		sort(all(res), comp2);
		char ctmp = arr[res[0].first];
		ret += ctmp;
		for (int i = 0; i < res.size(); i++) {
			if (ctmp == arr[res[i].first]) {
				if (v[res[i].first].empty()) continue;
				for (int k = 0; k < v[res[i].first].size(); k++) {
					if (v[res[i].first][k] == res[i].second) continue;
					else {
						nxt.push_back({ v[res[i].first][k],res[i].first });
					}
				}
				continue;
			}
			break;
		}
		res = nxt;
	}
	cout << ret;
}