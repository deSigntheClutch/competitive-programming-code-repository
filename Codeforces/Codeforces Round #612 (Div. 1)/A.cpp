#include <bits/stdc++.h>
using namespace std;

int n;
int a[123];
int dp[123][123][123][2];

int main() {
    cin >> n;
    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] & 1) odd += 1;
        else if (a[i] != 0) even += 1;
    }      
    even = n / 2 - even;
    odd = n - n / 2 - odd;
    memset(dp, 0x3f, sizeof dp);
    dp[0][even][odd][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int o = 0; o <= odd; o++) {
            for (int e = 0; e <= even; e++) {
                for (int c = 0; c < 2; c++) {
                    if (dp[i - 1][e][o][c] > 2 * n) continue;
                    if (a[i] != 0) {
                        dp[i][e][o][a[i]&1] = min(dp[i][e][o][a[i]&1], dp[i - 1][e][o][c] + (c == ((a[i]&1)^1) && i > 1));
                        continue;
                    }
                    if (e >= 1) dp[i][e - 1][o][0] = min(dp[i][e - 1][o][0], dp[i - 1][e][o][c] + (c == 1 && i > 1));
                    if (o >= 1) dp[i][e][o - 1][1] = min(dp[i][e - 1][o][1], dp[i - 1][e][o][c] + (c == 0 && i > 1));
                }
            }
        }
    }
    cout << min(dp[n][0][0][0], dp[n][0][0][1]) << endl;
    return 0;
}