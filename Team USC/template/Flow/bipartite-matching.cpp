int V;
vector<int> G[N];
int match[N];
bool used[N];

void add_edge(int u, int v) {
    G[u].push_back(v);
    G[v].push_back(u);
}

bool dfs(int v) {
    used[v] = true;
    for (int u : G[v]) {
        int w = match[u];
        if (w < 0 || !used[w] && dfs(w)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching() {
    int res = 0;
    memset(match, -1, sizeof match);
    for (int i = 0; i < V; i++) {
        if (match[i] != -1) continue;
        memset(used, 0, sizeof used);
        res += dfs(i);
    }
    return res;
}