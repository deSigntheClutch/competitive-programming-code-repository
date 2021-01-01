#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, m, vis[N], deg[N];
vector<pair<int, int>> G[N];

void dfs(int u) {
  for (int i = 0; i < G[u].size(); i++) {
    int x = G[u][i].second, v = G[u][i].first;
    if (!vis[x]) {
      vis[x] = 1;
      dfs(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int gen = 0, self_loop = 0;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    gen = u;
    if (v == u) {
      self_loop++;
    } else {
      deg[u]++;
      deg[v]++;
    }
    G[u].push_back(make_pair(v, i));
    G[v].push_back(make_pair(u, i));
  }
  dfs(gen);
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    if (!vis[i]) flag = true;
  }
  if (flag == true) {
    cout << 0 << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (long long)(deg[i] - 1) * deg[i] / 2;
  }
  ans += (long long)self_loop * (m - self_loop) + (long long)self_loop * (self_loop - 1) / 2;
  cout << ans << endl;
  return 0;
}

/*

5 3
1 2
2 3
4 5

*/

