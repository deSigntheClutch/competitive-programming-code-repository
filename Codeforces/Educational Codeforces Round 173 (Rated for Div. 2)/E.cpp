#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 1;

bool hasLoop;
int n, m, T;
int deg[N * 2];
bool used[N * 2], must[N * 2];
int a[N][N], b[N][N];
vector<int> G[N * 2];


bool check(){
      queue<int> q;
      for(int i = 1; i <= n + m; i++) {
            if(!must[i]) continue;
            fill(used, used + n + m + 1, 0);
            q.push(i), used[i] = 1;
            while(!q.empty()) {
                  int u = q.front();
                  q.pop();
                  for(int v : G[u]) {
                        if (v == i) return false;
                        if (!used[v]) q.push(v), used[v] = 1;
                  }
            }
      }
      return true;
}

bool check(int bit) {
      for (int i = 0; i <= n + m; i++) {
            G[i].clear();
            deg[i] = 0;
            must[i] = 0;
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  bool c = (a[i][j] >> bit) & 1;
                  bool d = (b[i][j] >> bit) & 1;

                  if (d == 0) {
                        G[n + j].push_back(i);
                        if (c == 1) {
                              must[i] = 1;
                        }
                  } else {
                        G[i].push_back(n + j);
                        if (c == 0) {
                              must[n + j] = 1;
                        }
                  }
            }
      }

//      for (int i = 1; i <= n + m; i++) {
//            if (!must[i]) continue;
//            hasLoop = false;
//            dfs(i, i);
//            if (hasLoop) return false;
//      }
      return check();
}


int main() {
      scanf("%d", &T);
      while (T--) {
            scanf("%d%d", &n, &m);
            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= m; j++) {
                        scanf("%d", &a[i][j]);
                  }
            }

            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= m; j++) {
                        scanf("%d", &b[i][j]);
                  }
            }

            bool flag = true;
            for (int bit = 0; bit < 30; bit++) {
                  if (!check(bit)) {
                        flag = false;
                        break;
                  }
            }

            if (flag) printf("yes\n");
            else printf("no\n");
      }
      return 0;
}
