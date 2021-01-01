#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e3 + 20;
const int INF = 2e9 + 20;
const int MAXV = 3000 + 20;
const int NINF = 1e9 + 10;

struct edge {
    int to, cap, rev;
};

int n, k;
ll p, a[N], b[N];
vector<edge> G[MAXV];
int level[MAXV], iter[MAXV];

ll cal(int u, int v) {
    return abs(a[u] - b[v]) + abs(b[v] - p);
}

void solveGreedy() {
    ll ans = 9e18;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + k);
    for (int l = 1; l + n - 1 <= k; l++) {
        ll v = 0;
        for (int j = 1; j <= n; j++) {
            v = max(v, cal(j, l + j - 1));
        }
        ans = min(ans, v);
    }
    printf("%I64d\n", ans);
}

ll f[N][N];

void solveDP() {
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + k);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= k; j++) {
            f[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= k; j++) {
            f[i][j] = min(f[i][j], max(f[i - 1][j - 1], cal(i, j)));
            if (j > i) f[i][j] = min(f[i][j], f[i][j - 1]);
        }
    }
    printf("%I64d\n", f[n][k]);
}

void init(int u) {
    for (int i = 0; i <= u; i++) {
        G[i].clear();
    }
}

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {
        to, cap, (int)G[to].size()
    });
    G[to].push_back((edge) {
        from, 0, (int)G[from].size() - 1
    });
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue <int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            } else {
                level[e.to] = -1;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof iter);
        int f;
        while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

bool check(int u) {
    int src = 0, sink = n + k + 1;
    init(sink);
    for (int i = 1; i <= n; i++) {
        add_edge(src, i, 1);
    }
    for (int i = 1; i <= k; i++) {
        add_edge(n + i, sink, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            ll cur = abs(a[i] - b[j]) + abs(b[j] - p);
            if (cur <= u) add_edge(i, j + n, 1);
        }
    }
    return max_flow(src, sink) == n;
}

void solveNetWorkFlow() {
    int l = 0, r = 2e9 + 1, md;
    for (int i = 0; i < 32; i++) {
        md = (l + r) >> 1;
        if (check(md)) r = md;
        else l = md + 1;
    }
    printf("%d\n", md);
}

int main() {
    scanf("%d%d%I64d", &n, &k, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", a + i);
    }
    for (int i = 1; i <= k; i++) {
        scanf("%I64d", b + i);
    }
    //solveDP();
    solveGreedy();
    //solveNetWorkFlow();
    return 0;
}
