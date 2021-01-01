#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;
const int P = 10 + 5;

int n, m, q;
vector<int> G[N];
pair<int, int> f[N][P];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int u, d, c;
    scanf("%d%d%d", &u, &d, &c);
    f[u][d] = make_pair(c, 1 + i);
  }
  for (int i = 10; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      if (f[j][i].first == 0) continue;
      for(int k = 0; k < (int)G[j].size(); k++) {
        int u = G[j][k];
        if(f[u][i - 1].second < f[j][i].second) {
          f[u][i - 1] = f[j][i];
        }
      }
      if(f[j][i - 1].second < f[j][i].second) {
        f[j][i - 1] = f[j][i];
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    printf("%d\n", f[i][0].first);
  }
  return 0;
}
