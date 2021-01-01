#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, m, a, b;
vector<int> G[3][N];
bool vis[3][N];
long long cnt[3];
long long t;
bool flag;

void dfs(int u, int id) {
    vis[id][u] = 1;
    if (id == 0 && u == b) flag = true;
    if (id == 1 && u == a) flag = true;
    t += 1;
    for (int x : G[id][u]) {
        if (!vis[id][x])
            dfs(x, id);
    }
}

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 3; i++) cnt[i] = 0;
        cin >> n >> m >> a >> b;
        for (int i = 1; i <= n; i++) {
            G[0][i].clear(), G[1][i].clear(), G[2][i].clear();
            vis[0][i] = 0, vis[1][i] = 0, vis[2][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            if (u != a && u != b && v != a && v != b) {
                G[2][u].push_back(v);
                G[2][v].push_back(u);
                G[1][u].push_back(v);
                G[1][v].push_back(u);
                G[0][u].push_back(v);
                G[0][v].push_back(u);
            }
            else if ((u == a || v == a) && u != b && v != b) {
                G[1][u].push_back(v);
                G[1][v].push_back(u);
            }
            else if ((u == b || v == b) && u != a && v != a) {
                G[0][u].push_back(v);
                G[0][v].push_back(u);
            } 
            else continue;
        }
        for (int id = 0; id < 3; id++) {
            for (int i = 1; i <= n; i++) {
            if (!vis[id][i]) {
                flag = false, t = 0;
                dfs(i, id);
                cnt[id] += t * (t - 1) / 2;
                if (flag) cnt[id] -= (t - 1);
            } 
         }
        }
        cout << (long long) (n - 2) * (n - 3) / 2 - cnt[0] - cnt[1] + cnt[2] << endl;
    }
    return 0;
}