// 11:27
#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int INF = 1e9 + 9;

int n;
int a[N], b[N];
int dp[N][1 << N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int k = 0; k <= n; k++) {
                if (dp[i][mask][k] > INF) continue;
                int pos = i;
                int last = (k ^ i & 1) ? b[i + 1] : a[i + 1];
                for (int j = 0; j < n; j++) { // 0-base
                    if (mask >> j & 1) continue;
                    pos += 1;
                    if (i & 1) {
                        if (j & 1) {
                            int val = a[j + 1];
                            if (val < last) continue;
                            dp[i + 1][mask | (1 << j)][j] = min(dp[i + 1][mask | (1 << j)][j], dp[i][mask][k] + abs(pos - i));
                        }
                        else {
                            int val = b[j + 1];
                            if (val < last) continue;
                            dp[i + 1][mask | (1 << j)][j] = min(dp[i + 1][mask | (1 << j)][j], dp[i][mask][k] + abs(pos - i));
                        }
                    } else {
                        if (j & 1) b[i + 1]
                        else a[i + 1]
                    }
                }
            }
        }
    }

    return 0;
}