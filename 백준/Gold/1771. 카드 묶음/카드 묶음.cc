#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) v.begin(),v.end()

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    stack<pair<int, int>> st;
    stack<int> s;
    int n; cin >> n;
    for (int i=1; i<=n; i++){
        int tmp; cin >> tmp;
        int a = tmp, b = tmp, k = i;
        while (1){
            if (st.empty()){
                st.push({ a, b });
                s.push(k);
                break;
            }
            int p = st.top().first, q = st.top().second;
            int l = s.top();
            if (a - q == 1) a = p;
            else if (p - b == 1) b = q;
            else{
                st.push({ a, b });
                s.push(k);
                break;
            }
            cout << l << '\n';
            st.pop(); s.pop();
        }
    }
}

