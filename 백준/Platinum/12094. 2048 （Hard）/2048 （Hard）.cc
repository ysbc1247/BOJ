#include <bits/stdc++.h>
#include<string>
#define endl "\n"
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;

int arr[25][25];
bool chk[25][25];
int n;
int temp;
int now;
int mx = -1e9;


int shift(int arr_temp[25][25], int dir) { // n ( 1 left , 2 right , 3 up , 4 down ) 
    int max_shift = 0;
    if (dir == 1) { //left
        for (int i = 0; i < n; i++) {
            for (int k = 1; k < n; k++) {
                if (arr_temp[i][k] != 0) {
                    temp = arr_temp[i][k];
                    now = k;
                    while (arr_temp[i][now - 1] == 0) {
                        now--;
                        if (now == 0) {
                            break;
                        }
                    }
                    if (now == 0) {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now] = temp;
                    }
                    else if (arr_temp[i][now - 1] == temp && !chk[i][now - 1]) {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now - 1] *= 2;
                        max_shift = max(2 * temp, max_shift);
                        chk[i][now - 1] = 1;
                    }
                    else {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now] = temp;
                    }
                    max_shift = max(temp, max_shift);

                }
            }
            max_shift = max(arr_temp[i][0], max_shift);
        }
    }
    else if (dir == 2) {
        for (int i = 0; i < n; i++) {
            for (int k = n - 2; k >= 0; k--) {
                if (arr_temp[i][k] != 0) {
                    temp = arr_temp[i][k];
                    now = k;
                    while (arr_temp[i][now + 1] == 0) {
                        now++;
                        if (now == n - 1) {
                            break;
                        }
                    }
                    if (now == n - 1) {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now] = temp;
                    }
                    else if (arr_temp[i][now + 1] == temp && !chk[i][now + 1]) {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now + 1] *= 2;
                        max_shift = max(2 * temp, max_shift);
                        chk[i][now + 1] = 1;
                    }
                    else {
                        arr_temp[i][k] = 0;
                        arr_temp[i][now] = temp;
                    }
                    max_shift = max(temp, max_shift);

                }
            }
            max_shift = max(arr_temp[i][n - 1], max_shift);
        }
    }
    else if (dir == 3) {

        for (int i = 0; i < n; i++) {
            for (int k = 1; k < n; k++) {
                if (arr_temp[k][i] != 0) {
                    temp = arr_temp[k][i];
                    now = k;
                    while (arr_temp[now - 1][i] == 0) {
                        now--;
                        if (now == 0) {
                            break;
                        }
                    }
                    if (now == 0) {
                        arr_temp[k][i] = 0;
                        arr_temp[now][i] = temp;
                    }
                    else if (arr_temp[now - 1][i] == temp && !chk[now - 1][i]) {
                        arr_temp[k][i] = 0;
                        arr_temp[now - 1][i] *= 2;
                        max_shift = max(2 * temp, max_shift);
                        chk[now - 1][i] = 1;
                    }
                    else {
                        arr_temp[k][i] = 0;
                        arr_temp[now][i] = temp;
                    }
                    max_shift = max(temp, max_shift);

                }
            }
            max_shift = max(arr_temp[0][i], max_shift);
        }

    }
    else {

        for (int i = 0; i < n; i++) {
            for (int k = n - 2; k >= 0; k--) {
                if (arr_temp[k][i] != 0) {
                    temp = arr_temp[k][i];
                    now = k;
                    while (arr_temp[now + 1][i] == 0) {
                        now++;
                        if (now == n - 1) {
                            break;
                        }
                    }
                    if (now == n - 1) {
                        arr_temp[k][i] = 0;
                        arr_temp[now][i] = temp;
                    }
                    else if (arr_temp[now + 1][i] == temp && !chk[now + 1][i]) {
                        arr_temp[k][i] = 0;
                        arr_temp[now + 1][i] *= 2;
                        max_shift = max(2 * temp, max_shift);
                        chk[now + 1][i] = 1;
                    }
                    else {
                        arr_temp[k][i] = 0;
                        arr_temp[now][i] = temp;
                    }
                    max_shift = max(temp, max_shift);

                }
            }
            max_shift = max(arr_temp[n - 1][i], max_shift);
        }

    }
    return max_shift;
}

bool no_change(int arr1[25][25], int arr2[25][25]) {
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (arr1[i][k] != arr2[i][k]) {
                return 0;
            }
        }
    }
    return 1;
}


void dfs(int cnt, int arr_now[25][25], int max_now) {
    if (cnt == 10) {
        mx = max(max_now, mx);
        return;
    }
    for (int i = 1; i <= 4; i++) {
        int board_temp[25][25];
        int max_next;

        copy(&arr_now[0][0], &arr_now[0][0] + 625, &board_temp[0][0]);

        max_next = shift(board_temp, i);
        mx = max(mx, max_next);
        if (!no_change(arr_now, board_temp) && mx < max_next * pow(2, 9 - cnt)) {
            for (int k = 0; k <= n; k++) {
                memset(chk[k], 0, sizeof(chk[k]));
            }
            dfs(cnt + 1, board_temp, max_next);
        }
        else {
            for (int k = 0; k <= n; k++) {
                memset(chk[k], 0, sizeof(chk[k]));
            }
        }
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> arr[i][k];
            mx = max(mx, arr[i][k]);
        }
    }
    dfs(0, arr, mx);
    cout << mx;

}
