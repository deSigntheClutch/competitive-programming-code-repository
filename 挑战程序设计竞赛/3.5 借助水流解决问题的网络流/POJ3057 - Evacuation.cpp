#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int N = 20;
const int MAXV = 100000 + 10;
const int INF = 1e8 + 10;

struct edge {
  int to, cap, rev;
};

int T, n, m, level[MAXV], iter[MAXV];
char nu[N][N];
vector <edge> G[MAXV];

void init() {
  for(int i = 0; i < MAXV; i++) G[i].clear();
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
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for(int i = 0; i < G[v].size(); i++) {
      edge &e = G[v][i];
      if(e.cap > 0 && level[e.to] < 0) {
        level[e.to] = level[v] + 1;
        q.push(e.to);
      }
    }
  }
}

int dfs(int v, int t, int f) {
  if(v == t) return f;
  for(int i = iter[v]; i < (int)G[v].size(); i++) {
    edge &e = G[v][i];
    if(e.cap > 0 && level[v] < level[e.to]) {
      int d = dfs(e.to, t, min(f, e.cap));
      if(d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      } else level[e.to] = -1;
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0, f;
  while(true) {
    bfs(s);
    if(level[t] < 0) return flow;
    memset(iter, 0, sizeof iter);
    while((f = dfs(s, t, INF)) > 0) flow += f;
  }
}

int main() {
  scanf("%d", &T);
  while(T--) {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      scanf("%s", nu[i]);
    }
    int ans = 0, sum = 0, fl = 0;
    int src = MAXV - 2, sink = MAXV - 1;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(nu[i][j] == 'X') continue;
        if(nu[i][j] == '.') {
          add_edge(src, i * m + j, 1);
          sum++;
          for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
              if(abs(dx) + abs(dy) <= 1) {
                int tx = i + dx, ty = j + dy;
                if(tx >= 0 && tx < n && ty >= 0 && ty < m && nu[tx][ty] != 'X') {
                  add_edge(i * m + j, m * n + tx * m + ty, 1);
                }
              }
            }
          }
        }
        if(nu[i][j] == 'D') {
          add_edge(m * n + i * m + j, sink, 1);
        }
      }
    }
    fl = max_flow(src, sink);
    while(true) {
      ans++;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
          if(nu[i][j] == 'X') continue;
          if(nu[i][j] == '.') {
            for(int dx = -1; dx <= 1; dx++) {
              for(int dy = -1; dy <= 1; dy++) {
                if(abs(dx) + abs(dy) <= 1) {
                  int tx = i + dx, ty = j + dy;
                  if(tx >= 0 && tx < n && ty >= 0 && ty < m && nu[tx][ty] != 'X') {
                    add_edge(m * n * ans + i * m + j, (ans + 1) * m * n + tx * m + ty, 1);
                  }
                }
              }
            }
          }
          if(nu[i][j] == 'D') {
            add_edge((ans + 1) * m * n + i * m + j, sink, 1);
          }
        }
      }
      int un = max_flow(src, sink);
      fl += un;
      if(!un) break;
    }
    if(sum == fl) {
      printf("%d\n", ans);
    } else {
      printf("impossible\n");
    }
  }
  return 0;
}

/*

4
3 7
XDXXDXX
X.....X
XXXXXXX
3 7
XDXDXXX
X.....X
XXXXXXX
3 7
XDXDXXX
X.....X
XXXXXXX

*/
