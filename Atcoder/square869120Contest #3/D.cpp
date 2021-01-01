#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 200 + 5;

int h, w;
int a[N][N];
int dp[2 * N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0][1][1] = a[1][1];
    for (int i = 1; i <= h + w - 2; i++) {
        int bound = min(i, h);
        for (int x1 = 1; x1 <= bound; x1++) {
            for (int x2 = 1; x2 <= bound; x2++) {
                if (dp[i - 1][x1][x2] == -1) continue;
                int base = dp[i - 1][x1][x2];
                int y1 = i + 1 - x1;
                int y2 = i + 1 - x2;
                if (x1 < h && x2 < h) dp[i][x1 + 1][x2 + 1] = max(dp[i][x1 + 1][x2 + 1], base + ((x1 == x2 && y1 == y2) ? a[x1 + 1][y1] : a[x1 + 1][y1] + a[x2 + 1][y2]));
                if (x1 < h && y2 < w) dp[i][x1 + 1][x2] = max(dp[i][x1 + 1][x2], base + ((x1 + 1 == x2 && y1 == y2 + 1) ? a[x2][y2 + 1] : a[x1 + 1][y1] + a[x2][y2 + 1]));
                if (y1 < w && x2 < h) dp[i][x1][x2 + 1] = max(dp[i][x1][x2 + 1], base + ((x1 == x2 + 1 && y1 + 1 == y2) ? a[x1][y1 + 1] : a[x1][y1 + 1] + a[x2 + 1][y2]));
                if (y1 < w && y2 < w) dp[i][x1][x2] = max(dp[i][x1][x2], base + ((x1 == x2 && y1 == y2) ? a[x1][y1 + 1] : a[x1][y1 + 1] + a[x2][y2 + 1]));
            }
        }
    }
    cout << dp[h + w - 2][h][h] << endl;
    return 0;
}