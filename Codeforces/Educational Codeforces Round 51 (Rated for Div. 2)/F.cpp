#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <map>

#define int long long

using namespace std;
const int N = 3e5 + 5;
const int M = 60 + 5;
const int INF = 2e14 + 10;
const int LOG_N = 20;

struct Edge {
    int from, to, cost;
    bool operator < (Edge e) const {
        return cost < e.cost;
    }
};

vector<Edge> tree_edge, nice_edge, T[N], G[N];
vector<int> nice_vertex;
vector<int> dis[M];
map<int, int> pos;

int n, m, q, total;
int pa[N];
int fa[LOG_N][N], cost[LOG_N][N], depth[N];

int find(int x) {
    if (pa[x] != x) return pa[x] = find(pa[x]);
    return pa[x];
}

void unite(Edge e) {
    int x = find(e.from);
    int y = find(e.to);
    if (x != y) {
        pa[x] = y;
        tree_edge.push_back(e);
        T[e.from].push_back({e.from, e.to, e.cost});
        T[e.to].push_back({e.to, e.from, e.cost});
    } else {
        nice_edge.push_back(e);
        nice_vertex.push_back(e.from);
        nice_vertex.push_back(e.to);
    }
}

void shortest_path(vector<int> src) {
    for (int i = 0; i < M; i++) {
        dis[i] = vector<int>(n + 1, INF);
    }
    for (int i = 0; i < src.size(); i++) {
        int s = src[i];
        pos[s] = i;
        priority_queue<pair<int, int>> Q;
        Q.push(make_pair(0, s));
        dis[i][s] = 0;
        while (!Q.empty()) {
            int t = Q.top().second;
            int v = -Q.top().first;
            Q.pop();
            for (Edge e : G[t]) {
                if (dis[i][e.to] > e.cost + v) {
                    dis[i][e.to] = e.cost + v;
                    Q.push(make_pair(-dis[i][e.to], e.to));
                }
            }
        }
    }
}

void dfs(int u, int f, int dep, int c) {
    fa[0][u] = f, depth[u] = dep, cost[0][u] = c;
    for (Edge e : T[u]) {
        if (e.to == f) continue;
        dfs(e.to, u, dep + 1, e.cost);
    }
}

void init_lca() {
    for (int i = 0; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i][j] = -1;
        }
    }
    dfs(1, -1, 0, 0);
    for (int i = 1; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            if (fa[i - 1][j] != -1) {
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
                cost[i][j] = min(INF, cost[i - 1][j] + cost[i - 1][fa[i - 1][j]]);
            }
        }
    }
}

int query(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    int w = depth[b] - depth[a], cnt = 0, res = 0;
    while (w) {
        if (w & 1) {
            res += cost[cnt][b];
            b = fa[cnt][b];
        }
        w >>= 1, cnt++;
    }
    if (a == b) return res;
    for (int i = LOG_N - 1; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            res += cost[i][b] + cost[i][a];
            a = fa[i][a], b = fa[i][b];
        }
    }
    return res + cost[0][a] + cost[0][b];
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        Edge e;
        cin >> e.from >> e.to >> e.cost;
        G[e.from].push_back({e.from, e.to, e.cost});
        G[e.to].push_back({e.to, e.from, e.cost});
        unite(e);
    }
    sort(nice_vertex.begin(), nice_vertex.end());
    nice_vertex.erase(unique(nice_vertex.begin(), nice_vertex.end()), nice_vertex.end());
    total = nice_vertex.size();
    shortest_path(nice_vertex);
    init_lca();
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        int res = query(u, v);
        for (Edge e : nice_edge) {
            int s = e.from, t = e.to, c = e.cost;
            res = min(res, dis[pos[t]][u] + dis[pos[s]][v] + c);
            res = min(res, dis[pos[s]][u] + dis[pos[t]][v] + c);
        }
        cout << res << endl;
    }
    return 0;
}