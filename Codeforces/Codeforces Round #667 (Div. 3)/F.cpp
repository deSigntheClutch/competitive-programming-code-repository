#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e2 + 5;

int T;
int n, le;
string a, b;
int dp[N][N][N];

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> le;
    cin >> a >> b;
    memset(dp, -1, sizeof dp);
    dp[0][0][le] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= le; k++) {
                if (dp[i][j][k] != -1) {
                    if (b[0] == b[1]) {
                        if (a[i] == b[0]) {
                            dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k] + j);
                        } else {
                            dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                            if (k >= 1) dp[i + 1][j + 1][k - 1] = max(dp[i + 1][j + 1][k - 1], dp[i][j][k] + j);
                        }
                        continue;
                    }
                    if (a[i] == b[0]) {
                        dp[i + 1][j + 1][k] = max(dp[i + 1][j + 1][k], dp[i][j][k]);
                        if (k >= 1) dp[i + 1][j][k - 1] = max(dp[i + 1][j][k - 1], dp[i][j][k] + j);
                    } else if (a[i] == b[1]) {
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + j);
                        if (k >= 1) dp[i + 1][j + 1][k - 1] = max(dp[i + 1][j + 1][k - 1], dp[i][j][k]);
                    } else {
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                        if (k >= 1) dp[i + 1][j + 1][k - 1] = max(dp[i + 1][j + 1][k - 1], dp[i][j][k]);
                        if (k >= 1) dp[i + 1][j][k - 1] = max(dp[i + 1][j][k - 1], dp[i][j][k] + j);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= le; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
