#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 1e4 + 2;
int dp[1000 + 2][4 * N];
int h, n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> h >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2 * N; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = a[i]; j < 2 * N; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j - a[i]] + b[i]);
        }
        //cout << *(dp[1] + 100) << endl;
    }
    cout << *min_element(dp[n] + h, dp[n] + 2 * N - 1) << endl;
    return 0;
}
