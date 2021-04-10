#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int N = 2e5 + 6;

int n, m, k;
int s[234567];
int c[234567];
int f[N], inv[N], finv[N];
// do initInv() at any time!!

int powMod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = res * u % MOD;
        v >>= 1;
        u = u * u % MOD;
    }
    return res;
}

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
    ios::sync_with_stdio(false);
    initInv();
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> s[i];
        sort(s + 1, s + n + 1, greater<int>());
        int cnt = 0;
        int l = 0;
        for (int i = 1; i <= k; i++) {
            if (s[i] == s[k]) cnt += 1;
        }
        for (int i = k + 1; i <= n; i++) {
            if (s[i] == s[k]) l += 1;
        }
        cout << C(cnt + l, cnt) % MOD << endl;
    }
    return 0;
}