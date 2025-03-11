#include <bits/stdc++.h>
using namespace std;


const int N = 2e5 + 5;


struct edge {
      int to;
      int from;
      int c;
};

int n, k;
int a[N];
vector<edge> G[N];
long long sz[N], sum[N], total;
long long ans;

void dfs(int u, int v) {
      sz[u] = 1;
      sum[u] = a[u];

      for (edge e : G[u]) {
            if (e.to == v) continue;
            dfs(e.to, u);
            sz[u] += sz[e.to];
            sum[u] += sum[e.to];
      }

      for (edge e : G[u]) {
            if (e.to == v) continue;
            ans += (long long) sz[e.to] * e.c * (total - sum[e.to]);
            ans += (long long) (n - sz[e.to]) * e.c * (sum[e.to]);
      }

}


int main() {
      cin >> n;

      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            total += a[i];
      }

      for (int i = 0; i < n - 1; i++) {
            int u, v, c;
            cin >> u >> v >> c;
            G[u].push_back({v, u, c});
            G[v].push_back({u, v, c});
      }

      dfs(1, -1);

      return 0;
}