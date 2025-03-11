#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

const int N = 1e5 + 5;
const int M = 5e5 + 5;

struct Edge {
      int u, v;
      int c;
      bool used;

      bool operator < (Edge e) const {
            return e.c < c;
      }
}e[M];

vector<pair<int, int>> G[N];
int fa[N], n, m, q, depth[N];
int parent[N][20], min_edge[N][20];

int find(int u) {
      if (fa[u] == u) return fa[u];
      return fa[u] = find(fa[u]);
}


void dfs(int u, int f, int dep) {
      parent[u][0] = f;
      depth[u] = dep;
      for (auto p : G[u]) {
            if (p.first == f) continue;

            min_edge[p.first][0] = p.second;
            dfs(p.first, u, dep + 1);
      }
}

int main() {
      cin >> n >> m;

      memset(min_edge, 0x3f, sizeof min_edge);
      memset(parent, -1, sizeof parent);

      for (int i = 1; i <= n; i++) fa[i] = i;

      for (int i = 1; i <= m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            e[i] = {a, b, c, false};
      }

      sort(e + 1, e + 1 + m);

      for (int i = 1; i <= m; i++) {
            int u = find(e[i].u);
            int v = find(e[i].v);

            if (u != v) {
                  fa[u] = v;
                  G[u].push_back(mp(v, e[i].c));
                  G[v].push_back(mp(u, e[i].c));
            }
      }

      for (int i = 1; i <= n; i++) {
            if (fa[i] == i) {
                  G[0].push_back(make_pair(i, 0));
                  G[i].push_back(make_pair(0, 0));
            }
      }

      dfs(0, -1, 0);

      for (int i = 1; i < 20; i++) {
            for (int j = 1; j <= n; j++) {
                  if (parent[j][i - 1] != -1) {
                        parent[j][i] = parent[parent[j][i - 1]][i - 1];
                        min_edge[j][i] = min(min_edge[j][i - 1], min_edge[parent[j][i - 1]][i - 1]);
                  }
            }
      }


      auto query = [=](int u, int v) {

            int res = INT_MAX;

            if (depth[u] < depth[v]) swap(u, v);
            int w = depth[u] - depth[v], cnt = 0;
            while (w) {
                  if (w & 1) {
                        res = min(res, min_edge[u][cnt]);
                        u = parent[u][cnt];
                  }
                  w >>= 1, cnt++;
            }
            if (u == v) return res;

            for (int i = 19; i >= 0; i--) {
                  if (parent[u][i] != parent[v][i]) {
                        res = min(res, min_edge[u][i]);
                        u = parent[u][i];
                        res = min(res, min_edge[v][i]);
                        v = parent[v][i];
                  }
            }
            res = min(res, min_edge[v][0]);
            res = min(res, min_edge[u][0]);

            return res;
      };

      cin >> q;
      for (int i = 1; i <= q; i++) {
            int u, v;
            cin >> u >> v;

            int ans = query(u, v);
            cout << ((ans == 0) ? -1 : ans) << endl;
      }

      return 0;
}