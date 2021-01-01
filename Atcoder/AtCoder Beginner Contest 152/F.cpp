#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 52;
const int MX = 1e6 + 1e5;

struct Edge {
    int to;
    int id;
};

int a[N], n, m;
vector<Edge> G[N];
int dep[N], father[N], fat_edge[N];
int edge[N];
int dp[N][MX];

void dfs(int u, int f, int depth, int idx) {
    dep[u] = depth;
    father[u] = f;
    fat_edge[u] = idx;
    for (Edge x : G[u]) {
        if (x.to == f) continue;
        dfs(x.to, u, depth + 1, x.id);
    }
}

void paint_path(int u, int v, int bit) {
    if (dep[u] > dep[v]) swap(u, v);
    while (dep[u] < dep[v]) {
        int tmp = fat_edge[v];
        edge[tmp] |= 1ll << bit;
        v = father[v];
    }
    while (u != v) {
        int tmp = fat_edge[v];
        edge[tmp] |= 1ll << bit;
        v = father[v];
        tmp = fat_edge[u];
        edge[tmp] |= 1ll << bit;
        u = father[u];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }
    dfs(1, -1, 0, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        paint_path(u, v, i);
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < MX; j++) {
            if (dp[i - 1][j] == 0) continue;
            dp[i][j | edge[i]] += dp[i - 1][j];
            dp[i][j] += dp[i - 1][j];
        }
    }
    cout << dp[n - 1][(1ll << m) - 1] << endl;
    return 0;
}
