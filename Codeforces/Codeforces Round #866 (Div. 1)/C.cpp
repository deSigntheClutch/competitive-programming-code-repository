#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
using namespace std;

const int N = 2e5 + 5;

vector<int> G[N];
int n, depth[N];
bool hasChild[N], hasSibling[N];

void dfs(int u, int f, int d) {
    depth[u] = d;
    int cnt = 0;
    for (int v : G[u]) {
        if (v == f) continue;
        hasChild[v] = true;
        cnt += 1;
        dfs(v, u, d + 1);
    }

    if (cnt >= 2) {
        for (int v : G[u]) {
            if (v == f) continue;
            hasSibling[v] = true;
        }
    }
}


int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, -1, 0);

    bool ans = true;
    for (int i = 1; i <= n; i++) {
    }
}
