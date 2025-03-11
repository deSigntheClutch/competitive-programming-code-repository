#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

vector<int> G[N];
int n, dp[N];

void dfs(int u, int f) {

      int numChild = 0;
      for (auto v : G[u]) {
            if (v == f) continue;
            dfs(v, u);
            numChild += 1;
      }

      priority_queue<int, vector<int>, greater<>> Q;

      for (auto v : G[u]) {
            if (v == f) continue;
            Q.push(dp[v]);
      }

      while(Q.size() > 1) {
            Q.pop();
            int y = Q.top();
            Q.pop();
            Q.push(y + 1);
      }

      if (Q.empty()) dp[u] = 0;
      else if (numChild == 1) dp[u] = Q.top() + 1;
      else dp[u] = Q.top();
      // cout << u << " " << dp[u] << endl;
}

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 2; i <= n; i++) {
                  int p;
                  cin >> p;
                  G[p].push_back(i);
            }

            fill(dp, dp + 1 + n, 0);

            dfs(1, -1);
            cout << dp[1] << endl;

            for (int i = 1; i <= n; i++) {
                  G[i].clear();
            }
      }
      return 0;
}
