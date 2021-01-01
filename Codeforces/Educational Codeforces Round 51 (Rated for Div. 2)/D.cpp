#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int n, k;
int dp[1002][2][2][2002];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    dp[1][0][0][1] = 1;
    dp[1][1][0][2] = 1;
    dp[1][0][1][2] = 1;
    dp[1][1][1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int up = 0; up < 2; up++) {
            for (int down = 0; down < 2; down++) {
                for (int comp = 1; comp <= 2 * i; comp++) {
                    if (dp[i - 1][up][down][comp] == 0) continue;
                    if (up == down) {
                        dp[i][0][1][comp + 1] = (dp[i][0][1][comp + 1] + dp[i - 1][up][down][comp]) % MOD;
                        dp[i][1][0][comp + 1] = (dp[i][1][0][comp + 1] + dp[i - 1][up][down][comp]) % MOD;
                        dp[i][1][1][comp + (up == 0)] = (dp[i][1][1][comp + (up == 0)] + dp[i - 1][up][down][comp]) % MOD;
                        dp[i][0][0][comp + (up == 1)] = (dp[i][0][0][comp + (up == 1)] + dp[i - 1][up][down][comp]) % MOD;
                    } else {
                        if (up == 0) {
                            dp[i][0][1][comp] = (dp[i][0][1][comp] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][1][0][comp + 2] = (dp[i][1][0][comp + 2] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][1][1][comp] = (dp[i][1][1][comp] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][0][0][comp] = (dp[i][0][0][comp] + dp[i - 1][up][down][comp]) % MOD;
                        } else {
                            dp[i][0][1][comp + 2] = (dp[i][0][1][comp + 2] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][1][0][comp] = (dp[i][1][0][comp] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][1][1][comp] = (dp[i][1][1][comp] + dp[i - 1][up][down][comp]) % MOD;
                            dp[i][0][0][comp] = (dp[i][0][0][comp] + dp[i - 1][up][down][comp]) % MOD;
                        }
                    }
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum = (sum + dp[n][i][j][k]) % MOD;
        }
    }
    cout << sum << endl;
    return 0;
}
