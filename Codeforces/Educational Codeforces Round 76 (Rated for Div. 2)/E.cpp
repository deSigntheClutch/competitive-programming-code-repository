#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int k1, k2, k3;
int n;
int a[N], b[N], c[N];
int f[N][4];
int dp[N];
int place[N];

int solve_dp1() {
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i < k1; i++) place[a[i]] = 1;
    for (int i = 0; i < k2; i++) place[b[i]] = 2;
    for (int i = 0; i < k3; i++) place[c[i]] = 3;

    f[0][1] = 0;
    f[0][2] = 0;
    f[0][3] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 3; j++) {
            if (j == 1) f[i][j] = f[i - 1][j] + (place[i] != j);
            else f[i][j] = min(f[i][j - 1], f[i - 1][j] + (place[i] != j));
        }
    }
    return f[n][3];
}

int solve_dp2() {
    memset(dp, 0x3f, sizeof dp);
    sort(a, a + k1);
    sort(b, b + k2);
    sort(c, c + k3);
    for (int i = 0; i < k1; i++) place[i] = a[i];
    for (int i = 0; i < k2; i++) place[i + k1] = b[i];
    for (int i = 0; i < k3; i++) place[i + k1 + k2] = c[i];
    for (int i = 0; i < n; i++) {
        dp[lower_bound(dp, dp + n, place[i]) - dp] = place[i];
    }
    return n - (lower_bound(dp, dp + n, 1000000) - dp);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;

    for (int i = 0; i < k1; i++) cin >> a[i];
    for (int i = 0; i < k2; i++) cin >> b[i];
    for (int i = 0; i < k3; i++) cin >> c[i];

    //int res = solve_dp1();
    int res = solve_dp2();
    // int res = solve();

    cout << res << endl;
    return 0;
}