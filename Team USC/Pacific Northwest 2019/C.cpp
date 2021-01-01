#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;
bool used[N];
vector<int> G[N];
int dis[N];

void bfs() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    used[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int e = q.front();
        q.pop();
        for (int v : G[e]) {
            if (dis[v] > dis[e] + 1 && used[v] == false) {
                used[v] = true;
                q.push(v);
                dis[v] = dis[e] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs();
    cout << dis[n] - 1 << endl;
    return 0;
}