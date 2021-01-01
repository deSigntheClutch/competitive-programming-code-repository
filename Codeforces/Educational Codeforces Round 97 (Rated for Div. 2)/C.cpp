#include <bits/stdc++.h>
using namespace std;

int vis[522];
int a[222], n;
int dp[522][522];
int cnt[333];

int cal(int id, int l, int r) {
    int pos = a[id];
    if (l <= pos && r >= pos) {
        int left_sum = pos * (pos - l + 1) - (l + pos) * (pos - l + 1) / 2;
        int right_sum = (r + pos) * (r - pos + 1) / 2 - pos * (r - pos + 1);
        return left_sum + right_sum;
    } else if (pos < l) {
        return (l + r) * (r - l + 1) / 2 - (r - l + 1) * pos;
    } else  {
        return (r - l + 1) * pos - (l + r) * (r - l + 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        memset(vis, 0, sizeof vis);
        memset(dp, 0x3f, sizeof dp);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]] += 1;
        }
        sort(a, a + n);
        int s = unique(a, a + n) - a;
        for (int i = 0; i < 511; i++) dp[0][i] = 0;
        for (int i = 0; i < s; i++) {
            //cout << cnt[a[i]] << a[i] << endl;
            for (int st = 0; st < 511; st++) {
                if (st + cnt[a[i]] < 511) {
                    dp[i + 1][st + cnt[a[i]]] = min(dp[i + 1][st + cnt[a[i]]], dp[i][st] + cal(i, st + 1, st + cnt[a[i]]));
                }
            }
            for (int st = 1; st < 511; st++) {
                dp[i + 1][st] = min(dp[i + 1][st], dp[i + 1][st - 1]);
            }
        }
//         for (int i = 0; i < s + 1; i++) {
//             for (int st = 0; st < 10; st++) {
// cout << dp[i][st] << " ";
//             }
//             cout << endl;
//         }
        int ans = 2e9 + 2;
        for (int i = 0; i < 511; i++) {
            ans = min(ans, dp[s][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
