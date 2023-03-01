#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define ll long long
#define np(v) while(next_permutation(v.begin(),v.end()))
using namespace std;

int uf[1000001];

int find(int a) {
	if (uf[a] == a) {
		return a;
	}
	return uf[a] = find(uf[a]);
}
void merge(int a, int b) {
	int pa = find(a); int pb = find(b);
	uf[pb] = pa;
}
int main() {
	fastio;
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		uf[i] = i;
	}
	while (m--) {
		int q, a, b; cin >> q >> a >> b;
		if (!q) {
			merge(a, b);
		}
		else {
			if (find(a) == find(b)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}