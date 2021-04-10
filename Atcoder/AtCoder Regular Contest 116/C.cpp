#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

vector<int> divi[N];
int n, m;
int dp[22][N];
int len;

int f[N], inv[N], finv[N];
// do initInv() at any time!!

void initInv() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
        finv[i] = (finv[i - 1] * inv[i]) % MOD;
    }
}

int C(int x, int y) {
    if (y < 0) return 0;
    return (f[x] * finv[y] % MOD) * finv[x - y] % MOD;
}

signed main() {
    initInv();

    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divi[j].push_back(i);
        }
    }

    for (int i = 1; i <= m; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i < 22; i++) {
        for (int j = 1; j <= m; j++) {
            for (int v : divi[j]) {
                dp[i][j] = (dp[i - 1][j / v] + dp[i][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 22; i++) {
        if (n - i < 0) break;
        for (int j = 1; j <= m; j++) {
            ans = (ans + dp[i][j] * C(n - 1, i - 1)) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}