#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define fs first
#define sc second
#define pb push_back
#define pq priority_queue
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n-1); i>=0; i--)
#define ms(v,k) memset(v,k,sizeof(v));
#define np(v) while(next_permutation(v.begin(),v.end()))
#define mkxy int dx[4]={1,-1,0,0}, dy[4] = {0,0,1,-1};
using namespace std;

int arr[501][501];
int mp[501][501];
bool v[501][501];
int mx; mkxy;
int n;
void solve(int a, int b) {
	v[a][b] = 1;
	bool chk = 0;
	rep(i, 4) {
		int tx = a + dx[i], ty = b + dy[i];
		if (tx >= 0 && tx < n && ty >= 0 && ty < n) {
			if (mp[tx][ty] > mp[a][b]) {
				if (!v[tx][ty]) {
					solve(tx, ty);
				}
				arr[a][b] = max(arr[a][b], 1 + arr[tx][ty]); chk = 1;
			}
		}
	}
	if (!chk) {
		arr[a][b] = 1; return;
	}
}
int main() {
	fastio;
	cin >> n;
	rep(i, n) {
		rep(k, n) {
			cin >> mp[i][k];
			arr[i][k] = 1;
		}
	}
	rep(i, n) {
		rep(k, n) {
			if (!v[i][k]) {
				solve(i, k);
			}
		}
	}
	rep(i, n) {
		rep(k, n) {
			mx = max(mx, arr[i][k]);
		}
	}
	cout << mx;
}