#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, k;
long long g[N][5], f[N][5], ans;
vector<int> G[N];

void dfs(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (fa == v) continue;
    dfs(v, u);
    for (int md = 0; md < k; md++) {
      for (int mu = 0; mu < k; mu++) {
        ans += g[v][md] * f[u][mu];
        ans += f[v][md] * g[u][mu];
        ans += f[v][md] * f[u][mu] * (long long) ceil(1.0 * (mu + md + 1) / k);
      }
    }
    for (int md = 0; md < k; md++) {
      if (md == k - 1) {
        g[u][0] += f[v][md];
      }
      g[u][(md + 1) % k] += g[v][md];
      f[u][(md + 1) % k] += f[v][md];
    }
  }
  ans += accumulate(g[u], g[u] + k, (long long)0);
  ans += accumulate(f[u] + 1, f[u] + k, (long long)0);
  f[u][0]++;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, -1);
  printf("%I64d\n", ans);
  return 0;
}

/*

6 1
1 2
1 3
2 4
2 5
4 6

*/
