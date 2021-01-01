#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n;
vector<int> G[N];
int f[N][2], g[N][2];

int pow_mod(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = (long long)res * u % MOD;
        v >>= 1;
        u = (long long)u * u % MOD;
    }
    return res;
}

void dfs(int u, int fa) {
    if ((int)G[u].size() == 1 && u != 1) {
        f[u][0] = f[u][1] = 1;
        return ;
    }
    int all[2] = {1, 1};
    for (int v : G[u]) {
        if (fa == v) continue;
        dfs(v, u);
        all[0] = (long long)all[0] * f[v][0] % MOD;
        all[1] = (long long)all[1] * f[v][1] % MOD;
    }
    f[u][0] = (all[0] + all[1]) % MOD;
    f[u][1] = f[u][0];
    for (int v : G[u]) {
        if (fa == v) continue;
        int t1 = 1, t0 = 1;
        if (fa != -1) t0 = g[fa][0], t1 = g[fa][1];
        g[v][0] = (long long)t0 * f[u][0] % MOD * pow_mod(2 * f[v][0], MOD - 2) % MOD;
        if (G[u].size() == 1 && G[u][0] == v) {
            g[v][1] = g[v][0];
        } else {
            g[v][0] = (g[v][0] + (long long)t1 * f[u][1] % MOD * pow_mod(2 * f[v][1], MOD - 2) % MOD) % MOD;
            g[v][1] = g[v][0];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    //  special 1
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            f[i][j] = g[i][j] = 1;
        }
    }
    dfs(1, -1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cout << i << " " << f[i][0] << " " << f[i][1] << " " << g[i][0] << " " << g[i][1] << endl;
        ans = (ans + (long long)f[i][0] * g[i][0] % MOD % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}
/*

3
1 2
1 3

*/
