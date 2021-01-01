#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int MAXV = 2000 + 20;
const int INF = 1e9 + 10;

int n, m, c;
int P[N], B[N];
vector<int> total[N];

class MaxFlow {

public:
  struct edge {
    int to, cap, rev;
  };
  vector<edge> G[MAXV];
  int level[MAXV], iter[MAXV], N, M;

  void init(int u) {
    for (int i = 0; i <= u; i++) G[i].clear();
  }

  void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {
      to, cap, (int)G[to].size()
    });
    G[to].push_back((edge) {
      from, 0, (int)G[from].size() - 1
    });
  }

  void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue <int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int i = iter[v]; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        int d = dfs(e.to, t, min(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        } else {
          level[e.to] = -1;
        }
      }
    }
    return 0;
  }
  int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
      bfs(s);
      if (level[t] < 0) return flow;
      memset(iter, 0, sizeof iter);
      int f;
      while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
  }
} q1;

class MCMF {
public:

  struct edge {
    int to, cap, cost, rev;
  };

  int V;
  vector<edge> G[MAXV];
  int h[MAXV];
  int dist[MAXV];
  int prevv[MAXV];
  int preve[MAXV];

  void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge) {
      to, cap, cost, (int)G[to].size()
    });
    G[to].push_back((edge) {
      from, 0, -cost, (int)G[from].size() - 1
    });
  }

  void init(int u) {
    for (int i = 0; i <= u; i++)
      G[i].clear();
  }

  int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while (f) {
      fill(dist, dist + V, INF);
      dist[s] = 0;
      bool update = true;
      while (update) {
        update = false;
        for (int v = 0; v < V; v++) {
          if (dist[v] == INF) continue;
          for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
              dist[e.to] = dist[v] + e.cost;
              prevv[e.to] = v;
              preve[e.to] = i;
              update = true;
            }
          }
        }
      }
      if (dist[t] == INF) return -1;
      int d = f;
      for (int v = t; v != s; v = prevv[v])
        d = min(d, G[prevv[v]][preve[v]].cap);
      f -= d;
      res += d * dist[t];
      for (int v = t; v != s; v = prevv[v]) {
        edge &e = G[prevv[v]][preve[v]];
        e.cap -= d;
        G[v][e.rev].cap += d;
      }
    }
    return res;
  }
} q2;

int flo[N], costa[N];

bool check(int u) {
  q1.init(n + c + 2);
  int src = 0, sink = n + c + 1;
  for (int i = 1; i <= c; i++) {
    q1.add_edge(src, i, (int)total[i].size());
  }
  for (int i = 1; i <= c; i++) {
    memset(flo, 0, sizeof flo);
    for (int v : total[i]) {
      flo[v]++;
    }
    for (int j = n; j >= 2; j--) {
      flo[j - 1] += flo[j];
    }
    for (int j = 1; j <= n; j++) {
      q1.add_edge(i, c + j, flo[j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    q1.add_edge(c + i, sink, u);
  }
  return q1.max_flow(src, sink) == m;
}

int cal(int u) {
  q2.init(n + c + 2);
  int src = 0, sink = n + c + 1;
  for (int i = 1; i <= c; i++) {
    q2.add_edge(src, i, (int)total[i].size(), 0);
  }
  for (int i = 1; i <= c; i++) {
      //printf("%d: \n", i);
    memset(flo, 0, sizeof flo);
    memset(costa, 0, sizeof costa);
    for (int v : total[i]) {
      flo[v]++;
      costa[v - 1]++;
    }
    for (int j = n; j >= 2; j--) {
      flo[j - 1] += flo[j];
      costa[j - 1] += costa[j];
    }
    for (int j = 1; j <= n; j++) {
     // printf("%d %d %d\n", j, costa[j], flo[j]);
      if(flo[j] - costa[j] > 0) q2.add_edge(i, c + j, flo[j] - costa[j], 0);
      if(costa[j] > 0) q2.add_edge(i, c + j, costa[j], 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    q2.add_edge(c + i, sink, u, 0);
  }
  q2.V = n + c + 2;
  return q2.min_cost_flow(src, sink, m);
}

int main() {
  ios::sync_with_stdio(false);
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> n >> c >> m;
    for (int i = 1; i <= c; i++) total[i].clear();
    int maxx = 1;
    for (int i = 1; i <= m; i++) {
      cin >> P[i] >> B[i];
      total[B[i]].push_back(P[i]);
      maxx = max((int)total[B[i]].size(), maxx);
    }
    int l = maxx, r = m, md;
    for (int cc = 0; cc < 11; cc++) {
      md = (l + r) >> 1;
      if (check(md)) r = md;
      else l = md + 1;
    }
    cout << md << " ";
    cout << cal(md) << endl;
  }
  return 0;
}

/*

3
2 2 2
2 1
2 2
2 2 2
1 1
1 2
2 2 2
1 1
2 1

*/
