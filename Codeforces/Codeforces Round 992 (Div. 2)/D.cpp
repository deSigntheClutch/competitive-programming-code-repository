#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int n, T;
vector<int> G[N];
bool vis[N];
int color[N];


void dfs(int u, int f) {
    for (int v : G[u]) {
        if (v == f) continue;
        if (abs(color[u] - color[v]) == 2) {
            color[v] = color[u] - 1;
            return;
        }
        dfs(v, u);
    }
}

int main() {

    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) G[i + 1].clear(), vis[i + 1] = false;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
            color[i] = 0;
        }

        queue<int> q;
        q.push(1);
        vis[1] = true;
        vector<int> blackNode;
        int blackCnt = 2 * n, whiteCnt = 2;

        while (!q.empty()) {

            int x = q.front();
            q.pop();
            bool isWhite = x > 0;

            if (isWhite) {// white
                color[x] = whiteCnt;
                whiteCnt += 2;
            } else {
                blackNode.push_back(-x);
            }

            for (int i = 0; i < G[abs(x)].size(); i++) {
                if (!vis[G[abs(x)][i]]) {
                    vis[G[abs(x)][i]] = true;
                    if (isWhite) q.push(-G[x][i]);
                    else q.push(G[-x][i]);
                }
            }
        }
        for (int x : blackNode) {
            color[x] = blackCnt;
            blackCnt -= 2;
        }

        dfs(1, -1);

        for (int i = 1; i <= n; i++) cout << color[i] << " ";
        cout << endl;
    }
    return 0;
}