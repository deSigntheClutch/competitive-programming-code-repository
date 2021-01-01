#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
string num;
int k;

int dp[202][2][10];

signed main() {
    ios::sync_with_stdio(false);
    cin >> num >> k;
    n = num.length();

    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int op = 0; op < 2; op++) {
            for (int j = 0; j <= 3; j++) {
                if (dp[i - 1][op][j] == -1) continue;
                for (int add = 0; add <= 9; add++) {
                    if (op == 0) {
                        if (add < num[i - 1] - '0') {
                            dp[i][1][j + (add > 0)] += dp[i - 1][op][j];
                        } else if (add == num[i - 1] - '0') {
                            dp[i][0][j + (add > 0)] += dp[i - 1][op][j];
                        }
                    } else {
                        dp[i][1][j + (add > 0)] += dp[i - 1][op][j];
                    }
                }
            }
        }
    }
    cout << dp[n][1][k] + dp[n][0][k] << endl;
    return 0;
}