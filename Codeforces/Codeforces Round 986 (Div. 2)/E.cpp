#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
vector<int> G[N];
int dp[N], deg[N];

int pow_mod(int u, int x) {
      int res = 1;
      while (x) {
            if (x & 1) res = (long long)res * u % MOD;
            x >>= 1;
            u = (long long)u * u % MOD;
      }
      return res;
}


void dfs(int u, int f) {

      for (int v : G[u]) {
            if (f == v) continue;
            dfs(u, v);
      }

      if (deg[u] == 1 && u != 1) {
            dp[u] = 0;
      }
}

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  G[i].clear();
                  deg[i] = 0;
                  dp[i] = 0;
            }

            for (int i = 0; i < n; i++) {
                  int u, v;
                  cin >> u >> v;
                  G[u].push_back(v);
                  G[v].push_back(u);
                  deg[u] += 1;
                  deg[v] += 1;
            }

            dp[1] = 1;
            dfs(1, -1);
      }
      return 0;
}