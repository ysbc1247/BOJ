#include <bits/stdc++.h>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define ll long long
using namespace std;

ll n, h;
ll mx;
int main() {
	fastio;
	cin >> n;
	mx = 0;
	stack<ll>height;
	stack<ll>hori;
	for (int ll i = 0; i < n; i++) {
		cin >> h;
		if (height.empty()) {
			height.push(h);
			hori.push(i);
		}
		else if (h >= height.top()) {
			height.push(h);
			hori.push(i);
		}
		else {
			ll tmp = 0;
			while (!height.empty() && height.top() > h) {
				ll tmp_ = height.top();
				tmp = hori.top();
				height.pop();
				hori.pop();
				ll sz = (i - tmp) * tmp_;
				mx = max(mx, sz);
			}
			height.push(h);
			hori.push(tmp);
		}
	}
	while (!height.empty()) {
		ll tmp_ = height.top();
		ll tmp = hori.top();
		height.pop();
		hori.pop();
		ll sz = (n - tmp) * tmp_;
		mx = max(mx, sz);
	}
	cout << mx << endl;


}