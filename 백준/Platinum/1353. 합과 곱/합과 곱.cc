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

    double s, p;
    cin >> s >> p;
    if (s == p) {
        cout << 1;
        return 0;
    }
    if (s > p) {
        cout << 2;
        return 0;
    }
    double max = 0;
    ll k = 0;
    for (double i = 1; i <= s; i++) {
        if (pow(s / i, i) >=p) {
            cout << i;
            return 0;
        }
    }
    cout << -1;

}