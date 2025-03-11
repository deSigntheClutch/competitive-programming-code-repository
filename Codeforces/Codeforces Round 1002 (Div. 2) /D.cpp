#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;
const ll INF = 1e18 + 1;

int n, m1, m2, s1, s2;
ll f[N][N];
bool endp[N], used[N][N];

vector<int> G[N], F[N];

struct State {
      int x, y;
      ll cost;

      bool operator < (State s) const {
            return cost > s.cost;
      }
};

inline int ffabs(int x, int y) {
      return x > y ? x - y : y - x;
}

inline ll ffmin(ll x, ll y) {
      return x > y ? y : x;
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0);
      int T; cin >> T; while (T--) {
            cin >> n >> s1 >> s2;

            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= n; j++) {
                        f[i][j] = INF;
                        used[i][j] = false;
                  }
                  G[i].clear();
                  F[i].clear();
                  endp[i] = false;
            }

            cin >> m1;

            for (int i = 1; i <= m1; i++) {
                  int a, b;
                  cin >> a >> b;
                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            cin >> m2;

            for (int i = 1; i <= m2; i++) {
                  int a, b;
                  cin >> a >> b;
                  F[a].push_back(b);
                  F[b].push_back(a);
            }

            for (int i = 1; i <= n; i++) {
                  bool flag = false;
                  for (int u : G[i]) {
                        for (int v: F[i]) {
                              if (u == v) {
                                    flag = true;
                              }
                        }
                  }
                  endp[i] = flag;
            }

            priority_queue<State> q;

            q.push({s1, s2,  0ll});
            f[s1][s2] = 0;

            ll ans = INF;

            while (!q.empty()) {
                  int x = q.top().x;
                  int y = q.top().y;
                  q.pop();

                  for (int u : G[x]) {
                        for (int v : F[y]) {
                              int cc = ffabs(u, v);
                              if (f[u][v] > f[x][y] + cc) {
                                    f[u][v] = f[x][y] + cc;
                                    q.push({u, v, f[u][v]});
                              }
                        }
                  }
            }

            for (int i = 1; i <= n; i++) {
                  if (endp[i])
                        ans = min(ans, f[i][i]);
            }
            cout << (ans == INF ? -1 : ans) << endl;
      }
      return 0;
}
