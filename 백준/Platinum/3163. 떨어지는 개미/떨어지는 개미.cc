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

bool com(pii a, pii b) {
	if (a.fs < b.fs) {
		return 1;
	}
	return 0;
}
bool cmp2(int a, int b) {
	return (abs(a) < abs(b));
}
int main() {
	fastio;
	int t; cin >> t;
	while (t--) {
		int a, b, c; cin >> a >> b >> c;
		deque<pii>v(a);
		
		for (int i = 0; i < a; i++) {
			int aa, bb; cin >> aa >> bb; v[i] = { aa,bb };
		}
		sort(all(v), com);
		vector<int>m;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].sc < 0) {
				m.push_back(-v[i].fs);
			}
			else {
				m.push_back(b - v[i].fs);
			}
		}
		sort(all(m), cmp2);
		vector<int>res;
		for (int i = 0; i < m.size(); i++) {
			if (i != m.size() - 1) {
				if (abs(m[i]) == abs(m[i + 1])) {
					if (v[0].sc < v[v.size() - 1].sc) {
						res.push_back(v[0].sc);
						res.push_back(v[v.size() - 1].sc);
						v.pop_back();
						v.pop_front();
						i++;
					}
					else {
						res.push_back(v[v.size() - 1].sc);
						res.push_back(v[0].sc);
						v.pop_back();
						v.pop_front();
						i++;
					}
				}
				else {
					if (m[i] < 0) {
						res.push_back(v[0].sc);
						v.pop_front();
					}
					else {
						res.push_back(v[v.size() - 1].sc);
						v.pop_back();
					}
				}
			}
			else {
				if (m[i] < 0) {
					res.push_back(v[0].sc);
					v.pop_front();
				}
				else {
					res.push_back(v[v.size() - 1].sc);
					v.pop_back();
				}
			}
		}
		cout << res[c - 1] << endl;
	}
}