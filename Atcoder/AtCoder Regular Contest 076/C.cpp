#include <bits/stdc++.h>
using namespace std;

const long long INF = 9e18;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

typedef long long ll;

int f[N], inv[N], finv[N];
int n, m;

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

int main() {
    ios::sync_with_stdio(false);
    initInv();
    cin >> n >> m;
    ll ans = 1;
    if (n > m) swap(n, m);
    if (m > n + 1) {
        cout << 0 << endl;
    } else if (m == n){
        cout << 2ll * f[n] % MOD * f[n] % MOD << endl;
    } else {
        cout << (ll)f[m] * f[n] % MOD << endl;
    }
    return 0;
}

