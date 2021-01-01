#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;

const double INF = 1e60;
const ll DINF = 1e18 + 10;
const int N = 1e2 + 5;
const double eps = 1e-9;

struct com {
  bool operator()( pair<double, int> &t1, pair<double, int> &t2)
  {
    if (t1.fi != t2.fi)
    return t1.fi - t2.fi < eps;
    return t1.se > t2.se ;
  }
};

int n, q;
ll d[N][N], e[N], s[N], dis[N][N];
double f[N];

void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        dis[i][j] = 0;
        continue;
      }
      if (d[i][j] == DINF) dis[i][j] = DINF;
      else dis[i][j] = d[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
      }
    }
  }
}

double solve(int u, int v) {
  for (int i = 1; i <= n; i++) {
    f[i] = INF;
  }
  f[u] = 0;
  priority_queue<pair<double, int>, vector<pair<double, int>>, com> Q;
  Q.push(make_pair(0, u));
  while (!Q.empty()) {
    double len = Q.top().fi;
    int id = Q.top().se;
    Q.pop();
    for (int i = 1; i <= n; i++) {
      if (i == id || dis[id][i] == DINF) continue;
      if (dis[id][i] > e[id]) continue;
      if (f[i] - (len + 1.0 * dis[id][i] / s[id]) > -eps) {
        f[i] = len + 1.0 * dis[id][i] / s[id];
        Q.push(make_pair(f[i], i));
      }
    }
  }
  return f[v];
}

int main() {
  ios::sync_with_stdio(false);
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
      cin >> e[i] >> s[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> d[i][j];
        if (d[i][j] == -1) d[i][j] = DINF;
      }
    }
    init();
    for (int i = 0; i < q; i++) {
      int u, v;
      cin >> u >> v;
      cout << setprecision(10) << solve(u, v);
      if (i == q - 1) cout << endl;
      else cout << " ";
    }
  }
  return 0;
}

