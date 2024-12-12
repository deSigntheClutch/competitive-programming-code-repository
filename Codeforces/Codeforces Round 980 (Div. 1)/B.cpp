#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 4e5 + 10;
const long long MAX = 1e18;

long long f[N], sum[N];
int n, b[N], a[N];
vector<pair<int, int>> G[N];

struct State {
  int cur;
  long long cost;
  bool operator < (struct State s) const {
    return cost > s.cost;
  }
};

int cal() {
  f[1] = 0;
  priority_queue<State> Q;
  Q.push((State) {
    1, 0
  });

  while (!Q.empty()) {
    int u = Q.top().cur, c = Q.top().cost;
    Q.pop();
    for (pair<int, int> x : G[u]) {
      int v = x.first, e = x.second;

      if (f[v] > e + f[u]) {
        Q.push((State) {
          v, e + c
        });
        f[v] = e + f[u];
      }
    }
  }
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      G[i].clear();
      cin >> a[i];
      sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
      f[i] = MAX;
      G[i].push_back(make_pair(b[i], a[i]));
      if (i > 1) {
        G[i].push_back(make_pair(i - 1, 0));
      }
    }

    cal();

    long long ans = a[1];
    for (int i = 2; i <= n; i++) {
      ans = max(sum[i] - f[i], ans);
    }
    cout << ans << endl;
  }
  return 0;
}
