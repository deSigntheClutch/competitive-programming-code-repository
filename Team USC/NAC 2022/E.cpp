#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e3 + 3;
const int M = 1e2 + 1;
const int S = 1e4 + 1;
const int INF = 1e10 + 1;

int n;
int v[N];
int f[N][S], g[N][S];
vector<int> fact[S];
vector<int> G[N];
bool np[S];

void dfs(int u, int p) {
      for (int x : G[u]) {
            if (x == p) continue;

            dfs(x, u);
      }

      for (int j = 2; j < S; j += 1) {
            if (j != v[u]) f[u][j] = j;
            else f[u][j] = 0;

            int cnt = 0;
            for (int x : G[u]) {
                  if (x == p) continue;

                  int mn = INF;
                  for (int y : fact[j]) {
                        mn = min(mn, g[x][y]);
                  }
                  cnt += mn;
            }
            f[u][j] += cnt;
      }

      for (int i = 2; i < S; i++) {
            if (np[i]) continue;

            int min_val = INF;
            for (int j = i; j < S; j += i) {
                  min_val = min(min_val, f[u][j]);
            }
            g[u][i] = min_val;
            assert(g[u][i] < INF);
      }
}


signed main() {
      for (int i = 0; i < N; i++) {
            for (int j = 0; j < S; j++) {
                  f[i][j] = INF;
            }
      }
      for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                  g[i][j] = INF;
            }
      }

      for (int i = 2; i < S; i++) {
            if (np[i]) continue;
            fact[i].push_back(i);
            for (int j = 2 * i; j < S; j += i) {
                  np[j] = true;
                  fact[j].push_back(i);
            }
      }

      cin >> n;

      for (int i = 1; i <= n; i++) {
            cin >> v[i];
      }

      for (int u, w, i = 0; i < n - 1; i++) {
            cin >> u >> w;
            G[u].push_back(w);
            G[w].push_back(u);
      }

      dfs(1, -1);

      int ans = INF;
      for (int i = 2; i < S; i++) {
            ans = min(ans, f[1][i]);
      }
      cout << ans << endl;
//
//      for (int i = 1; i <= 6; i++) {
//            for (int j = 1; j <= 12; j++) {
//                  cout << i << " " << j << " " << f[i][j] << " " << g[i][j] << endl;
//            }
//      }
      return 0;
}
