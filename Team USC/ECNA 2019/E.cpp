#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 2;
const int INF = 1e9 + 1;

int dp[N][N][12];
int r, c, n;
int a[N][N];
bool is_pass[N][N];
int dx[3] = {-1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c >> n;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i < r; i++) {
        for (int j = 2; j < c; j++) {
            if (a[i][j] == -1 || a[i + 1][j] == -1 || a[i - 1][j] == -1 || a[i][j + 1] == -1 || a[i][j - 1] == -1) continue;
            if (a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1] && a[i + 1][j] > a[i][j] && a[i - 1][j] > a[i][j]) {
                is_pass[i][j] = true;
            }
        }
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            for (int k = 0; k < 11; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        if (a[i][1] == -1) continue;
        dp[i][1][0] = a[i][1];
    }
    for (int i = 2; i <= c; i++) {
        for (int j = 1; j <= r; j++) {
            if (a[j][i] == -1) continue;

            for (int k = 0; k <= n; k++) {
                int mn = INF;
                for (int dir = 0; dir < 3; dir++) {
                    int tx = j + dx[dir], ty = i - 1;
                    if (tx > r || tx < 1 || a[tx][ty] == -1) continue;
                    mn = min(mn, dp[tx][ty][k]);
                }
                dp[j][i][k + is_pass[j][i]] = mn + a[j][i];
            }

        }
    }
    int ans = INF;
    for (int i = 1; i <= r; i++) {
        ans = min(ans, dp[i][c][n]);
    }
    if (ans >= INF) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}