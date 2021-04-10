#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge {
    int to, cap, cost, rev;
};

const int MAXV = 2000;
const int INF = 1e10;

vector<edge> G[MAXV];
int h[MAXV], dist[MAXV], prevv[MAXV], preve[MAXV];
int V;  // Please set the number of V (total number of nodes)!

void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
    G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}

int min_cost_flow(int s, int t, int f, int V) {
    int res = 0;
    while (f) {
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while (update) {
            update = false;
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if (dist[t] == INF) return -1;
        int d = f;
        for (int v = t; v != s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

const int N = 2e3 + 5;
int cal[N][N];
int n, m, M;
int a[3][N];

signed main() {
    V = 0;  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m >> M;
        for (int i = 0; i <= 2000; i++) {
            for (int j = 0; j <= 2000; j++) {
                cal[i][j] = (i + j) * (i ^ j) % M;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                add_edge(i * n + j, (i + 3) * n + j, 1, 0);
            }
        }
        int src = 0;
        V = 3 * n * 2 + 2;
        int sink = V - 1;

        for (int j = 1; j <= n; j++) {
            add_edge(src, n + j, 1, 0);
            add_edge(5 * n + j, sink, 1, 0);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                add_edge(4 * n + i, j, 1, -cal[a[1][i]][a[0][j]]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                add_edge(3 * n + i, 2 * n + j, 1, -cal[a[0][i]][a[2][j]]);
            }
        }
        cout << -min_cost_flow(src, sink, m, V) << endl;
        for (int i = 0; i < V; i++) G[i].clear();
    }
    return 0;
}
