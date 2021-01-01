#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

typedef long long int64;

vector<int> G[N];
int n, deg[N];
int64 x[N], y[N], r[N];
int64 f[N][2][2];

void dfs(int u) {
  if ((int)G[u].size() == 0) {
    f[u][0][0] = f[u][1][0] = r[u] * r[u];
    return ;
  }
  for (int v : G[u]) {
    dfs(v);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &x[i], &y[i], &r[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      long long dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      if (dis <= (r[i] - r[j]) * (r[i] - r[j]) && i != j && r[i] > r[j]) {
        G[i].push_back(j);
        deg[j]++;
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      dfs(i);
      ans += max(f[i][0][0], f[i][0][1]);
    }
  }
  printf("%.10f\n", ans);
  return 0;
}

