#include <bits/stdc++.h>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
typedef long long ll;
using namespace std;

ll n, m, k, t1, t2, t3;
ll init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	else {
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2) + init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}
void update(vector<ll>& tree, int node, int start, int end, int index, ll diff) {
	if (index<start || index>end) {
		return;
	}
	tree[node] = tree[node] + diff;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}
ll sum(vector<ll>& tree, int node, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}
int main() {
	fastio;
	cin >> n >> m >> k;
	vector<ll>arr(n);
	int pow = (int)ceil(log2(n));
	int tree_s = (1 << (pow + 1));
	vector<ll>tree(tree_s);
	m += k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(arr, tree, 1, 0, n - 1);
	while (m--) {
		cin >> t1;
		if (t1 == 1) {
			cin >> t2 >> t3;
			t2 -= 1;
			ll diff = t3 - arr[t2];
			arr[t2] = t3;
			update(tree, 1, 0, n - 1, t2, diff);
		}
		else if (t1 == 2) {
			cin >> t2 >> t3;
			cout << sum(tree, 1, 0, n - 1, t2 - 1, t3 - 1)<<endl;
		}
	}
}