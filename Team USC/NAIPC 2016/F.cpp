#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int N = 1e2 + 3;
const int M = 1e4 + 5;

int n, w, h;
int dp[N][M];

signed main() {
    cin >> n >> w >> h;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j <= h; j++) {
            for (int ribbon = 0; ribbon <= n - j; ribbon++) {
                dp[i][ribbon + j] = (dp[i - 1][ribbon] + dp[i][ribbon + j]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int ribbon = 0; ribbon <= n; ribbon++) {
        ans = (ans + dp[w][ribbon]) % MOD;
    }
    int plain = 0;
    for (int height = 0; height <= h; height++) {
        if (height * w <= n) {
            plain += 1;
        }
    }
    cout << (ans - plain + MOD) % MOD << endl;
    return 0;
}