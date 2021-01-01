struct edge {
    int to, cap, rev;
};

vector<edge> G[MAXV];
bool used[MAXV];
int n;

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {
        to, cap, (int)G[to].size()
    });
    G[to].push_back((edge) {
        from, 0, (int)G[from].size() - 1
    });
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (edge e : G[v]) {
        if (e.cap > 0 && !used[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            } 
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof used);
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}
