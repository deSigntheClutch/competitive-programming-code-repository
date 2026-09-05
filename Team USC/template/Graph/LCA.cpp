#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int LOG_N = 19;
const int INF = 1e9 + 10;

struct edge {
    int from, to, v, id;
    bool operator < (struct edge e) const {
        return v < e.v;
    }
};

int n, m, ans[N];
int fa[LOG_N][N], depth[N];
vector<edge> G[N];

void dfs(int u, int f, int dep) {
    fa[0][u] = f, depth[u] = dep;
    for (edge e : G[u]) {
        if (e.to == f) continue;
        dfs(e.to, u, dep + 1);
    }
}

void initLCA() {
    for (int i = 0; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i][j] = -1;
        }
    }
    dfs(1, -1, 0);
    for (int i = 1; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            if (fa[i - 1][j] != -1) {
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
            }
        }
    }
}

int query(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int w = depth[b] - depth[a], cnt = 0;
    while (w) {
        if (w & 1) b = fa[cnt][b];
        w >>= 1, cnt++;
    }
    if (a == b) return a;
    for (int i = LOG_N - 1; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            a = fa[i][a], b = fa[i][b];
        }
    }
    return fa[0][a];
}

int main() {
    return 0;
}
