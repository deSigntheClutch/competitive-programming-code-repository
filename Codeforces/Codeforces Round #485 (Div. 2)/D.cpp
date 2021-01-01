#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
  if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
  if (x < y) x = y;
}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;

priority_queue<int> ss[N];
vector<int> G[N];
vector<int> type[123];

int n, m, k, s;
int dis[N];
bool vis[N];

void bfs(vector<int> src) {
  memset(dis, 0x3f, sizeof dis);
  memset(vis, 0, sizeof vis);
  queue<int> Q;
  for (int v : src) {
    Q.push(v);
    dis[v] = 0;
    vis[v] = 1;
  }
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    for (int x : G[u]) {
      if (dis[x] > dis[u] + 1 && !vis[x]) {
        dis[x] = dis[u] + 1;
        Q.push(x);
        vis[x] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ss[i].size() < s) {
      ss[i].push(dis[i]);
      continue;
    }
    if (ss[i].top() > dis[i] && ss[i].size() == s) {
      ss[i].pop();
      ss[i].push(dis[i]);
      continue;
    }

  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    type[t].pb(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  }
  for (int t = 1; t <= k; t++) {
    bfs(type[t]);
  }
  for (int i = 1; i <= n; i++) {
    int ans = 0;
    while (!ss[i].empty()) {
      ans += ss[i].top();
      ss[i].pop();
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}

