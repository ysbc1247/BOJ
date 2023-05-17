#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int a[N], b[N], w, e;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> w >> e;
        a[w]++; b[e]++;
    }
    for (int i = 1; i < N; i++) {
        a[i] += a[i - 1]; b[i] += b[i - 1];
    }
    cin >> e;
    while (e--) {
        cin >> w;
        cout << a[w] - b[w - 1] << '\n';
    }
}