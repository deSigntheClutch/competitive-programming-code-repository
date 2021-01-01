#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> G[N];

int S[N], r;
int n, q;
long long x[N], y[N];

long long cross(int u, int v, int i) {
  long long x1 = x[i] - x[u], y1 = y[i] - y[u];
  long long x2 = x[i] - x[v], y2 = y[i] - y[v];
  return x1 * y2 - x2 * y1;
}

void construct_tree() {
  for (int i = 1; i <= n; i++) {
    if (r <= 1) S[r++] = i;
    else {
      while (r >= 2 && cross(S[r - 2], S[r - 1], i) < 0) {
        G[S[r - 1]].push_back(S[r - 2]);
        G[S[r - 2]].push_back(S[r - 1]);
        r--;
      }
      S[r++] = i;
    }
  }
  while (r >= 2) {
    G[S[r - 1]].push_back(S[r - 2]);
    G[S[r - 2]].push_back(S[r - 1]);
    r--;
  }
}

int fa[N][24], depth[N];

void dfs(int u, int f, int c) {
  fa[u][0] = f, depth[u] = c;
  for (int v : G[u]) {
    if (v == f) continue;
    dfs(v, u, c + 1);
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int len = depth[u] - depth[v];
  for (int i = 21; i >= 0; i--) {
    if (len >> i & 1) u = fa[u][i];
  }
  if (u == v) return v;
  for (int i = 21; i >= 0; i--) {
    if (fa[u][i] == fa[v][i]) continue;
    u = fa[u][i], v = fa[v][i];
  }
  return fa[u][0];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &x[i], &y[i]);
  }
  construct_tree();
  dfs(n, -1, 0);
  for (int i = 0; i < 22; i++) {
    for (int j = 1; j <= n; j++) {
      if (fa[j][i] == -1) fa[j][i + 1] = -1;
      else fa[j][i + 1] = fa[fa[j][i]][i];
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca(u, v));
  }
  return 0;
}

