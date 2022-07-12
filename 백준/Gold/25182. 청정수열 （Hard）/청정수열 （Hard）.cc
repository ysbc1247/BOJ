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

ll mx = 1e9 + 7;
int main() {
	ll n;
	ll tmp = 0;
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		tmp += i;
	}
	tmp %= mx;
	ll res = 0;
	for (ll i = 1; i <= n; i++) {
		res += (tmp + i) * i;
		res %= mx;
	}
	cout << res << ' ';
	res = 1;
	for (ll i = 1; i <= n; i++) {
		res *= i; res %= mx;
	}
	cout << (res * res) % mx;
}
