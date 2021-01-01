#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 100 + 5;

int a[N];
int n, k;
int dp[N][256][N];
int fact[111];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    fact[1] = 1;
    for (int i = 2; i < 110; i++) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 255; j++) {
            for (int w = 0; w <= i; w++) {
                if (dp[i][j][w] == 0) continue;
                dp[i + 1][j][w] = (dp[i + 1][j][w] + dp[i][j][w]) % MOD;
                dp[i + 1][j ^ a[i + 1]][w + 1] = (dp[i + 1][j ^ a[i + 1]][w + 1] + dp[i][j][w]) % MOD;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + (long long)fact[i] * dp[n][k][i] % MOD) % MOD;
    }
    cout << sum << endl;
    return 0;
}