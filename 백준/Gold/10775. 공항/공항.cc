#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
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

int g, P, a;
int p[100001];

int find(int x) {
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

int main() {
    fastio;
    int cnt = 0;
    cin >> g >> P;
    for (int i = 1; i <= g; i++)
        p[i] = i;

    for (int i = 1; i <= P; i++) {
        cin >> a;
        if (!find(a)) break;
        else {
            cnt++;
            p[find(a)] = find(find(a) - 1);
        }
    }
    cout << cnt;
}
