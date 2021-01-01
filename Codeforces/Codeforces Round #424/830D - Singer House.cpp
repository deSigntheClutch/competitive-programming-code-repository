#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 4e2 + 5;

int n, f[N][N];

int main() {
    scanf("%d", &n);
    f[1][0] = f[1][1] = 1;
    for (int top = 1; top < n; ++top) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n - i + 1; ++j) {
                int tmp = (ll)f[top][i] * f[top][j] % MOD;
                if (i + j <= n) f[top + 1][i + j] = (f[top + 1][i + j] + (ll)(2 * i + 2 * j + 1) * tmp % MOD) % MOD; // root excluded, root to left, root to right
                if (i + j + 1 <= n) f[top + 1][i + j + 1] = (f[top + 1][i + j + 1] + tmp) % MOD; // root alone
                if (i + j - 1 <= n) f[top + 1][i + j - 1] = (f[top + 1][i + j - 1] + (ll)(i + j - 1) * (i + j) % MOD * tmp % MOD) % MOD; // root to both
            }
        }
    }
    printf("%d\n", f[n][1]);
    return 0;
}

