#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int INF = 1e15;

int n, q;
int dp[N][2];
int a[N];

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];

            dp[i][0] = dp[i][1] = -INF;
        }
        int max_neg = 0;
        int max_pos = 0;
        int res = -INF;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(a[i], max_neg + a[i]);
            if (i > 1) dp[i][1] = max(dp[i][1], max_pos - a[i]);
            max_neg = max(max_neg, dp[i][1]);
            max_pos = max(max_pos, dp[i][0]);
            res = max(dp[i][0], res);
            res = max(dp[i][1], res);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        cout << res << endl;
    }
    return 0;
}