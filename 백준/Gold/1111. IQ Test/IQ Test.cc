#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<map>
#include<queue>
#include<functional>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int main() {
	fastio;
	int n;
	cin >> n;
	vector<double>v;
	double a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	if (n == 1) {
		cout << 'A';
		return 0;
	}
	if (n == 2) {
		if (v[0] == v[1]) {
			cout << v[0];
			return 0;
		}
		cout << 'A';
		return 0;
	}
	double x, y;
	if (v[1] == v[0]) {
		x = 0;
		y = v[1];
	}
	else {
		x = (v[2] - v[1]) / (v[1] - v[0]);
		y = v[1] - x * v[0];
	}
	if (x != (int)x) {
		cout << 'B';
		return 0;
	}
	for (int i = 0; i < n-1; i++) {
		if (!(x * v[i] + y == v[i + 1])) {
			cout << 'B'; 
			return 0;
		}
	}
	cout << x * v[n - 1] + y;


}


