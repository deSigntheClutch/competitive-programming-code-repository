bool used[MAXV];
int V, component_id[MAXV];
vector<int> G[MAXV], rG[MAXV], vs;

void add_edge(int from, int to) {
    G[from].pb(to), rG[to].pb(from);
}

void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        if (!used[G[v][i]])
            dfs(G[v][i]);
    }
    vs.pb(v);
}

void rdfs(int v, int k) {
    used[v] = true;
    component_id[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
        if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc() {
    memset(used, 0, sizeof used);
    vs.clear();
    for (int i = 0; i < V; i++) if (!used[i]) dfs(i);
    memset(used, 0, sizeof used);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}
