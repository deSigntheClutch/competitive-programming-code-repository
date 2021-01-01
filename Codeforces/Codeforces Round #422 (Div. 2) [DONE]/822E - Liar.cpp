#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll B = 53;
const int N = 1e5 + 10;
const int X = 50 + 5;

int n, m, x, f[N][X];
char s[N], t[N];
ll hashS[N], hashT[N], base[N];

void init() {
    int mx = max(n, m);
    base[0] = 1;
    for (int i = 1; i <= mx; i++) {
        base[i] = base[i - 1] * B % MOD;
    }
    for (int i = 1; i <= n; i++) {
        hashS[i] = (hashS[i - 1] + base[i] * (s[i] - 'a' + 1)) % MOD;
    }
    for (int i = 1; i <= m; i++) {
        hashT[i] = (hashT[i - 1] + base[i] * (t[i] - 'a' + 1)) % MOD;
    }
}

bool check(int u, int v, int len) {
    if (u + len - 1 > n || v + len - 1 > m) return false;
    ll a = (hashS[u + len - 1] - hashS[u - 1] + MOD) % MOD;
    ll b = (hashT[v + len - 1] - hashT[v - 1] + MOD) % MOD;
    if (u > v) b = (b * base[u - v]) % MOD;
    else a = (a * base[v - u]) % MOD;
    return a == b;
}

int calLCP(int u, int v) {
    int l = 0, r = n + 1, md;
    for (int i = 0; i < 30; i++) {
        md = (l + r) >> 1;
        if (check(u, v, md)) l = md + 1;
        else r = md;
    }
    return md - 1;
}

int main() {
    scanf("%d%s%d%s%d", &n, s + 1, &m, t + 1, &x);
    init();
    memset(f, -1, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (f[i][j] == -1) continue;
            if (j != x) {
                int len = calLCP(i + 1, f[i][j] + 1);
                f[i + len][j + 1] = max(f[i + len][j + 1], f[i][j] + len);
            }
            f[i + 1][j] = max(f[i + 1][j], f[i][j]);
        }
    }
    if (*max_element(f[n], f[n] + x + 1) < m) puts("NO");
    else puts("YES");
    return 0;
}

/*

1
r
1
r
2

*/
