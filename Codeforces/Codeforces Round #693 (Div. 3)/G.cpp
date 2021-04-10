#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, m;
int d[N];
int dp[N];
vector<int> G[N];
bool used[N];

void bfs() {
    queue<int> q;
    q.push(1);
    d[1] = 0;
    while (!q.empty()) {
        int id = q.front();
        for (int v : G[id]) {
            if (d[v] == -1) {
                d[v] = d[id] + 1;
                q.push(v);
            }
        }
        q.pop();
    }
}

void dfs2(int u) {
    used[u] = true;
    for (int x : G[u]) {
        if (d[x] > d[u]) {
            if (!used[x]) dfs2(x);
            dp[u] = min(dp[u], dp[x]);
        } else {
            dp[u] = min(dp[u], d[x]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            d[i] = -1;
            used[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
        }
        bfs();
        for (int i = 1; i <= n; i++) {
            dp[i] = d[i];
        }
        dfs2(1);
        for (int i = 1; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}