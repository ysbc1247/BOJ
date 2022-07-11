#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define endl "\n"
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

int main() {
	fastio;
	int n, m;
	vector<vector<pii>>v;
	cin >> n >> m;
	v.resize(n + 1);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	int qq, ww; cin >> qq >> ww;
	pii arr[1005] = {};
	rep(i, n + 1) {
		arr[i].sc = 2 * 1e9 + 9;
	}
	arr[qq].sc = 0;
	pq<pii>q;
	q.push({ 0,qq });
	while (!q.empty()) {
		int now = q.top().sc;
		int dis = -q.top().fs;
		q.pop();
		if (arr[now].sc < dis) { //어차피 최소비용으로 못갈때처리
			continue;
		}
		rep(i, v[now].size()) {
			int tmp = v[now][i].fs;
			int nxt = dis + v[now][i].sc;
			if (nxt < arr[tmp].sc) {
				arr[tmp].sc = nxt;
				arr[tmp].fs = now;
				q.push({ -nxt,tmp });
			}
		}

	}
	vector<int>res;
	int tmp = ww;
	res.push_back(ww);
	while (1) {
		if (tmp == qq) {
			break;
		}
		res.push_back(arr[tmp].fs);
		tmp = arr[tmp].fs;
	}
	cout << arr[ww].sc << endl;
	cout << res.size() << endl;
	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << ' ';
	}
}
	
