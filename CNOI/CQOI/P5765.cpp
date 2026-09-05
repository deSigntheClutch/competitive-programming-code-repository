#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int M = 11;

int n, l;
int f[M][N];
vector<int> G[N];


void dfs(int u, int p) {
      for (int i = 1; i < M; i++) f[i][u] = i;

      for (int v : G[u]) {
            if (p == v) continue;

            dfs(v, u);


            for (int i = 1; i < M; i++) {
                  int minf = N;
                  for (int j = 1; j < M; j++) {
                        if (i == j) continue;
                        minf = min(minf, f[j][v]);
                  }
                  f[i][u] += minf;
            }
      }
}

signed main() {
      cin >> n;
      for (int u,v,i = 1; i < n; i++) {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
      }

      dfs(1, -1);

      int ans = N;
      for (int i = 1; i < M; i++) {
            ans = min(ans, f[i][1]);
      }
      cout << ans << endl;
      return 0;
}