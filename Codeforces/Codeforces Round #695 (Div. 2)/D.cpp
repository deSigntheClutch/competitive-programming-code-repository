#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e3 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int n, k, q;
int a[N];
int dp[N][N];
int moves[N][N];
int coef[N];

int dfs(int u, int x) {
    if (x <= 0 || x > n) return 0;
    if (moves[u][x] != -1) return moves[u][x];
    int res = 0;
    res = (res + dfs(u - 1, x - 1)) % MOD;
    res = (res + dfs(u - 1, x + 1)) % MOD;
    return moves[u][x] = res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> q;
    k += 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(moves, -1, sizeof moves);
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
        moves[0][i] = 1;
        coef[i] = 0;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
    for (int j = 1; j <= n; j++) {
        moves[k][j] = dfs(k, j);
    }

    int ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            coef[j] = (coef[j] + dp[i][j] * moves[k - i][j] % MOD) % MOD;
            ans = (ans + dp[i][j] * moves[k - i][j] % MOD * a[j] % MOD) % MOD;
        }
    }
    for (int i = 1; i <= q; i++) {
        int id, x;
        cin >> id >> x;
        // cout << dp[k][id] * a[id] << endl;
        ans = (ans - coef[id] * a[id] % MOD + MOD) % MOD;
        // cout << ans << "-->";
        ans = (ans + coef[id] * x % MOD + MOD) % MOD;
        a[id] = x;
        cout << ans << endl;
    }
    return 0;
}