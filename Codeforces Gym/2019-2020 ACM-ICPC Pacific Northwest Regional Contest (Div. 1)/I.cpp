#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 3;

int V;
vector<int> G[N];
int match[N];
bool used[N];
string s[N];

void add_edge(int u, int v) {
      G[u].push_back(v);
      G[v].push_back(u);
}

bool dfs(int v) {
      used[v] = true;
      for (int u : G[v]) {
            int w = match[u];
            if (w < 0 || !used[w] && dfs(w)) {
                  match[v] = u;
                  match[u] = v;
                  return true;
            }
      }
      return false;
}

int bipartite_matching() {
      int res = 0;
      memset(match, -1, sizeof match);
      for (int i = 0; i < V; i++) {
            if (match[i] != -1) continue;
            memset(used, 0, sizeof used);
            res += dfs(i);
      }
      return res;
}

int main() {
      cin >> V;
      for (int i = 0; i < V; i++) {
            cin >> s[i];
      }
      for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                  int cnt = 0;
                  for (int k = 0; k < s[i].length(); k++) {
                        cnt += (s[i][k] != s[j][k]);
                  }
                  if (cnt == 2) {
                        add_edge(i, j);
                  }
            }
      }

      cout << V - bipartite_matching() << endl;
      return 0;
}