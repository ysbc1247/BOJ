#include <bits/stdc++.h>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int n, m, d;
int arr[17][17];
vector<vector<int>>v;
int mx = 0;
vector<pii>enemy;
int size_enemy;

int distance(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int a, int b, int c, int arr[17][17], vector<pii>enemy) {
    int cnt = 0;
    pii s_a = { n,a };
    pii s_b = { n,b };
    pii s_c = { n,c };

    while (1) {
        int max_temp = 1e9;
        pii erase_temp = { -1,-1 };
        vector<pii>erased;
        for (int i = 0; i < enemy.size(); i++) {
            if (distance(s_a, enemy[i]) < max_temp && distance(s_a, enemy[i]) <= d) {

                erase_temp = enemy[i];
                max_temp = distance(s_a, enemy[i]);

            }
            else if (distance(s_a, enemy[i]) == max_temp && distance(s_a, enemy[i]) <= d) {
                if (erase_temp.second > enemy[i].second) {
                    erase_temp = enemy[i];
                }
            }
        }
        erased.push_back(erase_temp);
        erase_temp = { -1,-1 };
        max_temp = 1e9;
        for (int i = 0; i < enemy.size(); i++) {
            if (distance(s_b, enemy[i]) < max_temp && distance(s_b, enemy[i]) <= d) {
                erase_temp = enemy[i];
                max_temp = distance(s_b, enemy[i]);
            }
            else if (distance(s_b, enemy[i]) == max_temp && distance(s_b, enemy[i]) <= d) {
                if (erase_temp.second > enemy[i].second) {
                    erase_temp = enemy[i];
                }
            }
        }
        erased.push_back(erase_temp);
        erase_temp = { -1,-1 };
        max_temp = 1e9;
        for (int i = 0; i < enemy.size(); i++) {
            if (distance(s_c, enemy[i]) < max_temp && distance(s_c, enemy[i]) <= d) {
                erase_temp = enemy[i];
                max_temp = distance(s_c, enemy[i]);
            }
            else if (distance(s_c, enemy[i]) == max_temp && distance(s_c, enemy[i]) <= d) {
                if (erase_temp.second > enemy[i].second) {
                    erase_temp = enemy[i];
                }
            }
        }
        erased.push_back(erase_temp);

        erased.erase(unique(erased.begin(), erased.end()), erased.end());
        for (int k = 0; k < erased.size(); k++) {
            for (int i = 0; i < enemy.size(); i++) {
                if (enemy[i] == erased[k]) {
                    enemy.erase(enemy.begin() + i);
                    break;
                }
            }
        }
        for (int i = 0; i < enemy.size(); i++) {
            enemy[i].first++;
            if (enemy[i].first > n - 1) {
                enemy.erase(enemy.begin() + i);
                i--;
                cnt++;
            }
        }
        if (enemy.empty()) {
            break;
        }
    }



    mx = max(mx, size_enemy-cnt);
}

int main() {
    fastio;
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> arr[i][k];
            if (arr[i][k] == 1) {
                enemy.push_back({ i,k });
            }
        }
    }
    for (int i = 0; i < m - 2; i++) {
        for (int k = i + 1; k < m - 1; k++) {
            for (int j = k + 1; j < m; j++) {
                v.push_back({ i,k,j });
            }
        }
    }

    int arr_temp[17][17];
    vector<pii>enemy_temp = enemy;
    size_enemy = enemy.size();

    copy(&arr[0][0], &arr[0][0] + 289,  &arr_temp[0][0] );

    for (int i = 0; i < v.size(); i++) {
        solve(v[i][0], v[i][1], v[i][2], arr_temp, enemy_temp);
    }
    cout << mx;
}
