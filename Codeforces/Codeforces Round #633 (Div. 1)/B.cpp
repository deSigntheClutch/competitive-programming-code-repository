#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> G[N];
int deg[N];
int dis1[N];
bool is_leaf[N];
int C;

void dfs1(int u, int f, int d) {
    dis1[u] = d;
    bool flag = true;
    for (int v : G[u]) {
        if (v == f) continue;
        flag = false;
        dfs1(v, u, d + 1);
    }
    is_leaf[u] = flag;
}

void dfs2(int u, int f) {
    bool has_edge_to_leaf = false;
    for (int v : G[u]) {
        if (v == f) continue;
        if (is_leaf[v]) has_edge_to_leaf = true;
        else C += 1;
        dfs2(v, u);
    }
    C += has_edge_to_leaf;
} 

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u] += 1;
        deg[v] += 1;
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 1) {
            root = i;
            break;
        }
    }
    dfs1(root, -1, 0);

    int cnt[2] = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (is_leaf[i]) {
            cnt[dis1[i] & 1] += 1;
        }
    }

    if (cnt[0] > 0 && cnt[1] > 0) {
        cout << 3 << " ";
    } else {
        cout << 1 << " ";
    }
    C = 0;
    dfs2(root, -1);
    cout << C << endl;
    return 0;
}