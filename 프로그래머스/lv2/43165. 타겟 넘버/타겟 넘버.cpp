#include<bits/stdc++.h>

using namespace std;
int tmp;
int answer = 0;
int sz;
vector<int>vv;
void dfs(int a, int b) {
    if (b > tmp) {
        return;
    }
    if (a == sz) {
        if (b == tmp) {
            answer++;
        }
        return;
    }
    if (tmp - b >= 0) {
        dfs(a + 1, b + vv[a]);
        dfs(a + 1, b);
    }
}
int solution(vector<int> v, int t) {
    sz = v.size();
    
    int tot = 0;
    sort(v.begin(), v.end());
    vv = v;
    for (int i = 0; i < v.size(); i++) {
        tot += v[i];
    }
    if (t == tot) {
        return 1;
    }
    if ((-t + tot) % 2)
        return answer;

    tmp = (-t + tot) / 2;

    dfs(1, v[0]);
    dfs(1, 0);

    return answer;
}
