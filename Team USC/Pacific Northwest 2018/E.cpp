#include <bits/stdc++.h>
using namespace std;
const int MAXV = 5000 + 20;
const long long INF = 1e11 + 5;

const int X = 100;

struct edge {
    int to;
    long long cap, rev;
};

vector<edge> G[MAXV];
int level[MAXV], iter[MAXV];
int n, m, c;
int src, sink;

void add_edge(int from, int to, long long cap) {
    G[from].push_back((edge) {
        to, cap, (int)G[to].size()
    });
    G[to].push_back((edge) {
        from, 0, (int)G[from].size() - 1
    });
}

bool bfs(int s) {
    memset(level, -1, sizeof(level));
    queue <int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (!e.cap || ~level[e.to]) continue;
            level[e.to] = level[v] + 1;
            q.push(e.to);
            if (e.to == sink) return 1;
        }
    }
    return 0;
}

long long dfs(int v, int t, long long f) {
    if (v == t) return f;
    long long y = 0, z = 0;
    for (int i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (level[e.to] == level[v] + 1 && (z = dfs(e.to, t, min(f, e.cap)))) {
            e.cap -= z;
            G[e.to][e.rev].cap += z;
            y += z;
            f -= z;
        }
        if (!f) break;
    }
    return y;
}

long long max_flow(int s, int t) {
    long long flow = 0;
    for (;bfs(s);memset(iter, 0, sizeof iter)) flow += dfs(s, t, INF);
    return flow;
}

void init() {
    for (int i = 0; i <= n + 1; i++) {
        G[i].clear();
    }
}

char grid[X][X];
int cost[X];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

signed main() {
    
    scanf("%d%d%d", &m, &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < c; i++) {
        scanf("%d", cost + i);
    }
    
    sink = 3 * n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                src = i * m + j; 
                for (int dir = 0; dir < 4; dir++) {
                    int tx = dx[dir] + i, ty = dy[dir] + j;
                    if (tx < 0 || ty < 0 || ty >= m || tx >= n) {
                        add_edge(src, sink, INF);
                    } else {
                        add_edge(src, tx * m + ty, INF);
                    }
                }
                continue;
            }
            if (grid[i][j] == '.') add_edge(i * m + j, i * m + j + (n * m), INF);
            else add_edge(i * m + j, i * m + j + (n * m), (long long)cost[grid[i][j] - 'a']);

            for (int dir = 0; dir < 4; dir++) {
                int tx = dx[dir] + i, ty = dy[dir] + j;
                if (tx < 0 || ty < 0 || ty >= m || tx >= n) {
                    add_edge(i * m + j + (m * n), sink, INF);
                } else if (grid[tx][ty] != 'B') {
                    add_edge(i * m + j + (m * n), tx * m + ty, INF);
                }
            }
        }
    }
    long long ans = max_flow(src, sink);
    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

/*

5 5 1
aaaaa
a...a
a.B.a
a...a
aaaaa
1

2 2 1
aB
aa
1

3 3 1
.a.
aBa
.a.
1

1 1 1
B
1





*/