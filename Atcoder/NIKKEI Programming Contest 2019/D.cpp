#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;

vector<int> G[N];
int n, m;
int deg[N];
int parent[N];

int main() {
      cin >> n >> m;
      for (int i = 1; i <= n - 1 + m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            deg[v] += 1;
      }

      int V = 0;

      for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) V = i;
      }

      queue<int> Q;
      Q.push(V);

      while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int v : G[x]) {
                  deg[v] -= 1;
                  if (deg[v] == 0) {
                        Q.push(v);
                        parent[v] = x;
                  }
            }
      }

      for (int i = 1; i <= n; i++) {
            cout << parent[i] << endl;
      }
      return 0;
}