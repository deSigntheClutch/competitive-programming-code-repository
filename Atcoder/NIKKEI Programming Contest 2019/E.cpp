#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

struct edge {
      int u, v;
      int cost;
      bool operator < (struct edge e) const {
            return cost < e.cost;
      }
}E[N];

int n, m;
int X[N], Y[N];
int fa[N], weights[N], num[N];
vector<int> unused[N];

int find(int x) {
      if (fa[x] == x) return fa[x];
      return fa[x] = find(fa[x]);
}


void _union(int x, int y) {
      x = find(x), y = find(y);
      if (x != y) {
            fa[x] = y;
            weights[y] += weights[x];
      }
}

int main() {
      cin >> n >> m;

      for (int i = 1; i <= n; i++) {
            cin >> X[i];
      }
      for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            E[i] = (edge) {
                  u, v, w
            };
      }

      sort(E + 1, E + 1 + m);

      long long sum = 0;
      for (int i = 1; i <= m; i++) {
            int u = find(E[i].u), v = find(E[i].v);
            long long cur_weight = 0;
            if (u != v) {
                  cur_weight = weights[u] + weights[v];
            } else {
                  cur_weight = weights[u];
            }

            if ()
      }

      return 0;
}