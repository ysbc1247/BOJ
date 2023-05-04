#include <bits/stdc++.h>
#include<string>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;


int main(){
	fastio;

	ll arr[30010] = {}, add[30010] = {};
	ll n, now = 0, res = 0;

	cin >> n;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < n; i++){
		arr[i + n] = arr[i];
		now += arr[i];
	}

	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			add[j + 1] = add[j] + arr[i + j];
			if (add[j + 1] < 0) {
				res += (-add[j + 1] + now - 1) / now;
			}
		}
	}
	cout << res;
}