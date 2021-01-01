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

bool used[N], isnnecessary[N];
int n, m, ans[N];
int pa[N];
int fa[LOG_N][N], maxl[LOG_N][N], depth[N];
vector<edge> G[N], a, T;
vector<int> event[N];
multiset<int> status[N];
map<int, int> app[N];

void initDSU() {
    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
}

int find(int x) {
    return x == pa[x] ? pa[x] : pa[x] = find(pa[x]);
}

void kruskal() {
    sort(a.begin(), a.end());
    initDSU();
    for (edge e : a) {
        int u = find(e.from), v = find(e.to);
        if (u != v) {
            pa[u] = v;
            T.push_back(e);
        }
    }
    for (edge e : T) {
        used[e.id] = true;
        int u = e.from, v = e.to, w = e.v, i = e.id;
        G[u].push_back((edge) {
            u, v, w, i
        });
        G[v].push_back((edge) {
            v, u, w, i
        });
    }
}

void dfs1(int u, int f, int dep) {
    fa[0][u] = f, depth[u] = dep;
    for (edge e : G[u]) {
        if (e.to == f) continue;
        maxl[0][e.to] = e.v;
        dfs1(e.to, u, dep + 1);
    }
}

void initLCA() {
    for (int i = 0; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            fa[i][j] = -1;
            maxl[i][j] = 0;
        }
    }
    dfs1(1, -1, 0);
    for (int i = 1; i < LOG_N; i++) {
        for (int j = 1; j <= n; j++) {
            if (fa[i - 1][j] != -1) {
                fa[i][j] = fa[i - 1][fa[i - 1][j]];
                maxl[i][j] = max(maxl[i - 1][j], maxl[i - 1][fa[i - 1][j]]);
            }
        }
    }
}

pair<int, int> query(int a, int b) {
    int lca = -1, mx = 0;
    if (depth[a] > depth[b]) swap(a, b);
    int w = depth[b] - depth[a], cnt = 0;
    while (w) {
        if (w & 1) mx = max(mx, maxl[cnt][b]), b = fa[cnt][b];
        w >>= 1, cnt++;
    }
    if (a == b) {
        lca = a;
        return make_pair(lca, mx);
    }
    for (int i = LOG_N - 1; i >= 0; i--) {
        if (fa[i][a] != fa[i][b]) {
            mx = max(mx, maxl[i][a]);
            mx = max(mx, maxl[i][b]);
            a = fa[i][a], b = fa[i][b];
        }
    }
    lca = fa[0][a], mx = max(max(mx, maxl[0][b]), maxl[0][a]);
    return make_pair(lca, mx);
}

void dfs2(int u, int f) {
    int id = 0, mx = -1;
    for (edge e : G[u]) {
        if (e.to == f) continue;
        dfs2(e.to, u);
        if ((int)status[e.to].size() > mx) {
            id = e.to;
            mx = (int)status[e.to].size();
        }
        int v = e.id;
        if (!status[e.to].empty()) {
            isnnecessary[v] = true;
            ans[v] = (int)(*status[e.to].begin()) - 1;
        }
    }
    if (id != 0) {
        swap(status[id], status[u]);
        swap(app[id], app[u]);
        for (edge e : G[u]) {
            if (e.to == f || id == e.to) continue;
            for (multiset<int>::iterator it = status[e.to].begin(); it != status[e.to].end(); it++) {
                if(app[e.to][*it] > 0) status[u].insert(*it);
            }
            for (map<int, int>::iterator it = app[e.to].begin(); it != app[e.to].end(); it++) {
                if(it->second > 0) app[u][it->first] += it->second;
            }
        }
    }
    for (int x : event[u]) {
        if (x > 0) {
            app[u][x]++;
            if (app[u][x] == 1) status[u].insert(x);
        } else {
            app[u][-x]--;
            if (app[u][-x] == 0) status[u].erase(-x);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        a.push_back(edge{u, v, w, i});
    }
    kruskal();
    initLCA();
    for (edge e : a) {
        if (used[e.id]) continue;
        pair<int, int> t = query(e.from, e.to);
        ans[e.id] = t.second - 1;
        if (t.first == e.to) swap(e.from, e.to);
        if (t.first == e.from) {
            event[e.from].push_back(-e.v);
            event[e.to].push_back(e.v);
        } else {
            event[t.first].push_back(-e.v);
            event[e.from].push_back(e.v);
            event[t.first].push_back(-e.v);
            event[e.to].push_back(e.v);
        }
    }
    dfs2(1, -1);
    for (int i = 1; i <= m; i++) {
        if (!isnnecessary[i] && used[i]) printf("-1 ");
        else printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

/*

20 38
12 18 6
20 2 3
4 9 7
13 17 3
17 12 6
7 8 2
7 20 5
18 5 7
14 11 1
11 12 2
16 2 9
6 11 4
14 10 2
17 9 5
9 20 7
10 9 1
4 7 3
5 9 4
4 2 6
19 17 5
13 11 3
16 8 1
2 5 9
14 4 6
19 1 2
13 14 8
3 12 1
1 18 1
15 13 7
8 14 4
20 18 9
17 2 8
15 20 7
2 10 2
3 20 1
18 8 10
16 6 7
6 1 2

*/
