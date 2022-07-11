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
	ll arr[21] = {0, 0,1, 2, 5, 16, 61, 272, 1385, 7936, 50521, 353792, 2702765, 22368256, 199360981, 1903757312, 19391512145, 209865342976, 2404879675441, 29088885112832, 370371188237525 };
	for (int i = 1; i <= 20; i++) {
		arr[i] *= 2;
	}
	arr[1] = 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		cout << arr[a] << endl;
	}
}
