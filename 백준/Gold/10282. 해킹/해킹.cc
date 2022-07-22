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

int n, m, d, c;
vector<vector<pii>>v;
int arr[300005];

void dijk() {
	queue<pii>q;
	q.push({ 0,c });
	while (!q.empty()) {
		int tmp = q.front().sc;
		int dis = -q.front().fs;
		q.pop();
		rep(i, v[tmp].size()) {
			int nxt = v[tmp][i].fs;
			int ndis = v[tmp][i].sc;
			if (dis + ndis < arr[nxt]) {
				q.push({ -dis - ndis ,nxt });
				arr[nxt] = dis + ndis;
			}
		}
	}
}
int main() {
	fastio;
	int t; cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		v.clear();
		v.resize(n + 1);
		ms(arr, 0);
		rep(i, n + 1) {
			arr[i] = 1e9;
		}
		arr[c] = 0;
		while (d--) {
			int a, b, e; cin >> a >> b>>e;
			v[b].push_back({ a,e });
		}
		dijk();
		int cnt = 0;
		int mx = 0; int tmp;
		rep(i, n + 1) {
			if (arr[i] != 1e9) {
				if (arr[i] > mx) {
					tmp = i; mx = arr[i];
				}
				cnt++;
			}
		}
		cout << cnt << ' ' << mx << endl;
	}
}


