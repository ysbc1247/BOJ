#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<regex>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;


int main() {
	fastio;
	int t;
	cin >> t;
	const double pi = 3.14159265358979;
	double r, v;
	for (int i = 0; i < t; i++) {
		cin >> r >> v;
		cout << fixed;
		cout.precision(10);
		cout << "Case " << i + 1 << ": ";
		cout << 2 * pi * r / 4 / v << endl;
	}
	
}

