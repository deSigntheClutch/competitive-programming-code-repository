#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<pair<int, int>> G[N];
int vis[N], n, m;

int dfs(int u) {
  queue<int> Q;
  for (pair<int, int> v : G[u]) {
    if (vis[v.first]) continue;
    vis[v.first] = 1;
    int res = dfs(v.second);
    if (res == 0) {
      Q.push(v.second);
      if (Q.size() == 2) {
        printf("%d ", Q.front());
        Q.pop();
        printf("%d ", u);
        printf("%d\n", Q.front());
        Q.pop();
      }
    } else {
      printf("%d %d %d\n", u, v.second, res);
    }
  }
  return (Q.empty()) ? 0 : Q.front();
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(make_pair(i, v));
    G[v].push_back(make_pair(i, u));
  }
  if (m & 1) {
    printf("No solution\n");
    return 0;
  }
  dfs(1);
  return 0;
}

