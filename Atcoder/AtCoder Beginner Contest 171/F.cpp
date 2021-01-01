#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int f[N], inv[N], finv[N];
// inv[]: inverse element

int powMod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = (ll)res * u % MOD;
        v >>= 1;
        u = (ll) u * u % MOD;
    }
    return res;
}

void initInv() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = (ll)f[i - 1] * i % MOD;
    }
    inv[0] = inv[1] = 1;
    for (int i = 2; i < N; i++) {
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = finv[1] = 1;
    for (int i = 2; i < N; i++) {
        finv[i] = ((ll)finv[i - 1] * inv[i]) % MOD;
    }
}

int C(int x, int y) {
    if (y < 0) return 0;
    return ((ll)f[x] * finv[y] % MOD) * finv[x - y] % MOD;
}

int Lucas(int u, int v) {
    if (v == 0) return 1;
    return (ll)C(u % MOD, v % MOD) * Lucas(u / MOD, v / MOD) % MOD;
}

int k, n, ans;
string s;

int main() {
    ios::sync_with_stdio(false);
    initInv();
    cin >> k >> s;
    n = s.length();
    for (int pref = 0; pref <= k; pref++) {
        ans = (ans + ((ll)powMod(26ll, pref) * powMod(25ll, k - pref) % MOD * Lucas(n + k - 1 - pref, n - 1) % MOD)) % MOD;
    }
    cout << ans << endl;
    return 0;
}