#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 80;
const int LOG_N = 18;
const int INF = 1e17 + 10;

struct edge {
    int from, to, v, id;
    bool operator < (struct edge e) const {
        return v < e.v;
    }
}e[N];

int n, m, q;
int fa[LOG_N][N], depth[N], cost[LOG_N][N];
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

int father[N], cnt;
bool used[N];
map<int, int> good_point;
vector<int> good_point_v;
int dis[66][N];
vector<edge> unused;

int find(int x) {
    if (father[x] != x) return father[x] = find(father[x]);
    return father[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].from >> e[i].to >> e[i].v;
        e[i].id = i;
    }
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x = find(e[i].from);
        int y = find(e[i].to);
        if (x != y) {
            father[x] = y;
            used[i] = true;
            G[e[i].from].push_back(e[i]);
            G[e[i].to].push_back((edge){e[i].to, e[i].from, e[i].v, e[i].id});
        }
    }
    initLCA();
    dij();
    for (int i = 0; i < m; i++) {
        if (used[i]) continue;
        unused.push_back(e[i]);
        if (!good_point[e[i].from]) good_point[e[i].from] = cnt++, good_point_v.push_back(e[i].from);
        if (!good_point[e[i].to]) good_point[e[i].to] = cnt++, good_point_v.push_back(e[i].to);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int ans = query(u, v);
        for (edge ev: unused) {

        }

    }
    return 0;
}
