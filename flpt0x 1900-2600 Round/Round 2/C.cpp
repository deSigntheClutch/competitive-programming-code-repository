#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 1e9 + 7;

struct Edge {
      int from, to;
      int c1, c2;
};

struct Status {
      int v;
      int t;

      bool operator < (struct Status s) const {
            return t > s.t;
      }
};

int n, m, t0, t1, t2;
vector<Edge> G[N];
int f[N];
bool used[N];

bool not_overlap_with_phone(int l, int r) {
      int a = l, b = r, c = t1, d = t2;

      if (a > c) {
            swap(a, c);
            swap(b, d);
      }

      if (b <= c) return true;
      else return false;
}


bool check(int s) {

      for (int i = 1; i <= n; i++) {
            f[i] = INF;
            used[i] = false;
      }
      f[1] = s;
      priority_queue<Status> Q;
      Q.push({1, s});

      while(!Q.empty()) {
            int v = Q.top().v;

            Q.pop();
            if (used[v]) continue;

            used[v] = true;
            for (Edge e : G[v]) {
                  // walk
                  int to = e.to;
                  int cost_bus = e.c1;
                  int cost_foot = e.c2;
                  if (f[to] > (ll) f[v] + cost_foot) {
                        f[to] = f[v] + cost_foot;
                        Q.push({to, f[to]});
                  }


                  // bus
                  if ((ll) f[v] + cost_bus <= INF && not_overlap_with_phone(f[v], f[v] + cost_bus)) {
                        if (f[to] > f[v] + cost_bus) {
                              f[to] = f[v] + cost_bus;
                              Q.push({to, f[to]});
                        }
                  } else if ((ll) f[v] + cost_bus <= INF && !not_overlap_with_phone(f[v], f[v] + cost_bus)) {
                        if (f[to] > t2 + cost_bus) {
                              f[to] = t2 + cost_bus;
                              Q.push({to, f[to]});
                        }
                  }
            }
      }
      return f[n] <= t0;
}

void cleanup() {
      for (int i = 1; i <= n; i++) {
            G[i].clear();
      }
}


int main() {

      int T; cin >> T; while (T--) {
            cin >> n >> m;
            cin >> t0 >> t1 >> t2;

            for (int u,v,c1,c2,i = 0; i < m; i++) {
                  cin >> u >> v >> c1 >> c2;
                  G[u].push_back({u,v,c1,c2});
                  G[v].push_back({v,u,c1,c2});
            }


            int l = 0, r = 1e9 + 1, md;

            for (int i = 0; i < 34; i++) {
                  md = (l + r) >> 1;
                  if (check(md)) l = md + 1;
                  else r = md;
            }

            cout << l - 1 << endl;

            cleanup();
      }
      return 0;
}
