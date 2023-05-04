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

int n, w;
int arr[1001][3];
int dp[1001][1001];

int s3(int from, int to){
	if (!from) {
		return abs(arr[to][1] - n) + abs(arr[to][2] - n);
	}
	return abs(arr[to][1] - arr[from][1]) + abs(arr[to][2] - arr[from][2]);
}
int s2(int from, int to){
	if (!from) {
		return abs(arr[to][1] - 1) + abs(arr[to][2] - 1);
	}
	return abs(arr[to][1] - arr[from][1]) + abs(arr[to][2] - arr[from][2]);
}
void trc(int x, int y){
	int z = max(x, y) + 1;
	if (z == w) {
		if (dp[x][y] == s2(x, z)) {
			cout << 1 << endl;
			return;
		}

		if (dp[x][y] == s3(y, z)) {
			cout << 2 << endl;
			return;
		}
	}
	if (dp[x][y] - s2(x, z) == dp[z][y]) {
		cout << 1 << endl;
		trc(z, y);
		return;
	}

	if (dp[x][y] - s3(y, z) == dp[x][z]) {
		cout << 2 << endl;
		trc(x, z);
	}
}
int s1(int one, int two){
	if (one == w || two == w) {
		return 0;
	}
	int& ret = dp[one][two];
	if (ret != -1) {
		return ret;
	}
	return ret = min(s1(max(one, two) + 1, two) + s2(one, max(one, two) + 1), s1(one, max(one, two) + 1) + s3(two, max(one, two) + 1));

}
int main(){
	fastio;
	memset(dp, -1, sizeof(dp));
	cin >> n >> w;
	for (int i = 1; i <= w; ++i) {
		cin >> arr[i][1] >> arr[i][2];
	}
	cout << s1(0, 0) << endl;
	trc(0, 0);
}