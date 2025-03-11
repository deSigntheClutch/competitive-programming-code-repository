#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, deg[N];
vector<int> G[N];
bool isLeaf[N], notAdjToLeaf[N];
int dp1[N];

long long ans;

void dfs1(int u, int f) {
      dp1[u] = notAdjToLeaf[u];
      for (int v : G[u]) {
            if (f == v) continue;
            dfs1(v, u);
            dp1[u] += dp1[v];
      }
}


void dfs2(int u, int f) {
      bool hasAdjLeaf = false;
      for (int v : G[u]) {
            hasAdjLeaf |= isLeaf[v];
            if (f == v) {
                  continue;
            }
            dfs2(v, u);
      }

      if (!isLeaf[u] && hasAdjLeaf) {
            for (int from : G[u]) {
                  int pCnt = 0;
                  if (from == f) {
                        pCnt = dp1[u];
                  } else {
                        pCnt = dp1[1] - dp1[from];
                  }

                  if (!isLeaf[from]) {
                        ans += pCnt;
                  }
            }
      }
}

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;

            fill(deg, deg + 1 + n, 0);
            fill(isLeaf, isLeaf + 1 + n, 0);
            fill(notAdjToLeaf, notAdjToLeaf + 1 + n, 0);
            for (int i = 1; i <= n; i++) {
                  G[i].clear();
                  dp1[i] = 0;
            }

            for (int i = 0; i < n - 1; i++) {
                  int u, v;
                  cin >> u >> v;
                  G[u].push_back(v);
                  G[v].push_back(u);
                  deg[u] += 1;
                  deg[v] += 1;
            }

            int leaf = 0;

            for (int i = 1; i <= n; i++) {
                  leaf += (deg[i] == 1);
                  isLeaf[i] = (deg[i] == 1);
            }

            ans = (long long)(n - leaf) * leaf;

            //cout << ans << endl;

            for (int i = 1; i <= n; i++) {
                  if (isLeaf[i]) continue;
                  bool flag = true;

                  for (int j : G[i]) {
                        if (isLeaf[j]) {
                              flag = false;
                        }
                  }
                  notAdjToLeaf[i] = flag;
            }

//            for (int i = 1; i <= n; i++) {
//                  cout << notAdjToLeaf[i] << " ";
//            }
//            cout << endl;

            dfs1(1, -1);
            dfs2(1, -1);

//            for (int i = 1; i <= n; i++) {
//                  cout << dp2[i] << " ";
//            }
//            cout << endl;

            cout << ans << endl;
      }
      return 0;
}