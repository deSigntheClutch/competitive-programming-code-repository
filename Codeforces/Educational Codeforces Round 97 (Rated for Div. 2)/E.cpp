#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
const int INF = 2e9 + 5;

int n, k;
int a[N], b[N], dp[N];

int solve(int l, int r) {
    if (l > r) return 0;
    int len = r - l + 1;
    for (int i = 0; i <= len; i++) {
        dp[i] = INF;
    }
    for (int i = l + 1; i <= r; i++) {
        if (a[i] > a[r + 1] || a[i] < a[l]) continue;
        int pos = upper_bound(dp, dp + 1 + len, a[i]) - dp;
        dp[pos] = a[i];
    }
    return len - 1 - (lower_bound(dp, dp + 1 + len, INF) - dp);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i + 1];
    }
    a[0] = -INF, b[0] = 0;
    a[n + 1] = INF; b[k + 1] = n + 1;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        int l = b[i], r = b[i + 1];
        if (a[l] > a[r]) {
            cout << -1 << endl;
            return 0;
        }
        ans += solve(l, r - 1);
    }
    cout << ans << endl;
    return 0;
}
