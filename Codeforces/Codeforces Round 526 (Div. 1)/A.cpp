#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int n;
vector<pair<int, ll>> G[N];
ll w[N], f[N], g[N]; // f: n -> leaf, g: leaf -> n
ll ans = 0;

void dfs(int u, int fa) {

      ll maxf = w[u], maxg = w[u];
      vector<pair<ll, int>> v_maxf, v_maxg;

      for (auto [v, c] : G[u]) {
            if (fa == v) continue;

            dfs(v, u);

            if (w[u] - c >= 0) {
                  maxf = max(maxf, f[v] + w[u] - c);
                  //cout << v << " f: " << f[v] + w[u] - c << endl;
                  v_maxf.push_back({f[v] + w[u] - c, v});
            }
            if (g[v] - c >= 0) {
                  maxg = max(maxg, g[v] + w[u] - c);
                  //cout << v << " g: " << g[v] + w[u] - c << endl;
                  v_maxg.push_back({g[v] + w[u] - c, v});
            }
      }

      f[u] = maxf; g[u] = maxg;

      //cout << u << " " << f[u] << " " << g[u] << " " << v_maxf.size() << " " << v_maxg.size() << endl;

      ans = max(f[u], ans);
      ans = max(ans, g[u]);

      sort(v_maxf.begin(), v_maxf.end(), greater<>());
      sort(v_maxg.begin(), v_maxg.end(), greater<>());

      for (int i = 0; i < 3; i++) {
            if (i >= v_maxf.size()) break;

            for (auto [v, c] : G[u]) {
                  if (v_maxf[i].second == v || v == fa) continue;

                  if (g[v] >= c) ans = max(ans, v_maxf[i].first + g[v] - c);
            }
      }

      for (int i = 0; i < 3; i++) {
            if (i >= v_maxg.size()) break;

            for (auto [v, c] : G[u]) {
                  if (v_maxg[i].second == v || v == fa) continue;

                  if (v_maxg[i].first >= c) ans = max(ans, v_maxg[i].first + f[v] - c);
            }
      }
}


int main() {
      cin >> n;
      for (int i = 1 ; i <= n; i++) cin >> w[i];

      for (int u,v,c, i = 1; i < n; i++) {
            cin >> u >> v >> c;
            G[u].push_back({v, c});
            G[v].push_back({u, c});
      }

      dfs(1, -1);

      cout << ans << endl;
      return 0;
}

/*
 *
 *

10
81 34 31 38 69 62 54 18 72 29
4 8 12
2 9 25
4 5 17
5 7 35
10 1 13
9 3 53
7 6 22
1 6 82
3 10 42

 */