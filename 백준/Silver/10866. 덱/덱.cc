#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<regex>
#include<stack>
#include<deque>
#define endl "\n"
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;


int main() {
	fastio;
	deque<int>v;
	int n;
	cin >> n;
	string s;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push_back") {
			cin >> a;
			v.push_back(a);
		}
		else if (s == "push_front") {
			cin >> a;
			v.push_front(a);
		}

		else if (s == "pop_front") {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << v.front() << endl;
				v.pop_front();
			}

		}
		else if (s == "pop_back") {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << v.back() << endl;
				v.pop_back();
			}

		}
		else if (s == "size") {
			cout << v.size() << endl;
		}
		else if (s == "empty") {
			if (v.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s == "front") {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << v.front() << endl;

			}
		}
		else if (s == "back") {
			if (v.empty()) {
				cout << -1 << endl;
			}
			else {
				cout << v.back() << endl;
			}
		}
	}
}






