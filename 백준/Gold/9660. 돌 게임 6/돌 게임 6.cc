#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define ll long long
#define np(v) while(next_permutation(v.begin(),v.end()))
#define makex int dx[4]={1,-1,0,0};
#define makey int dy[4]={0,0,1,-1};
#define pb push_back
using namespace std;


int main() {
	fastio;
	ll n; cin >> n;
	n %= 7;
	if (n == 0 || n == 2) {
		cout << "CY"; return 0;
	}
	cout << "SK";
}