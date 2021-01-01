#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int T;
int n, k;
int x[N], y[N];
int dp[2][N]; // left, right;

signed main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            dp[0][i] = dp[1][i] = 0;
        }
        dp[0][n + 1] = dp[1][n + 1] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> y[i];
        }
        sort(x + 1, x + 1 + n);
        int pt = 1;
        for (int i = 1; i <= n; i++) {
            while (x[pt] + k < x[i]) pt += 1;
            dp[0][i] = max(dp[0][i - 1], i - pt + 1);
        }
        pt = n;
        for (int i = n; i >= 1; i--) {
            while (x[pt] - k > x[i]) pt--;
            dp[1][i] = max(dp[1][i + 1], pt - i + 1);
        }
        int ans = 1;
        pt = 1;
        for (int i = 1; i <= n; i++) {
            while (x[pt] + k < x[i]) pt += 1;
            //cout << i << ": "<< dp[0][pt - 1] << " " << i - pt + 1 << " " << dp[1][i + 1] << endl;
            ans = max(ans, max(dp[0][pt - 1],  dp[1][i + 1]) + + i - pt + 1);
        }
        cout << ans << endl;
    }
    return 0;
}
