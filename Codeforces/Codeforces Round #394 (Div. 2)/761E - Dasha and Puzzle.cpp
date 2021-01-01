#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug0(x) printf("! %d\n", x);
#define debug1(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define nono(x, ite) for(__typeof((x).begin()) (ite)=(x).begin();(ite)!=(x).end();(ite++))

typedef long long ll;

const int N = 33;
const ll INF = 1e18;
vector<int> G[N];

int n, deg[N];
ll dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

pair<ll, ll> co[N];

void dfs(int u, int f, ll x, ll y, int depth, int from) {
  co[u] = mp(x, y);
  int dir = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f) continue;
    ll pace = 1ll << (58 - 2 * depth);
    if(from != -1 && dir == (from + 2) % 4) dir++;
    ll tx = x + pace * dx[dir];
    ll ty = y + pace * dy[dir];
    dfs(v, u, tx, ty, depth + 1, dir);
    dir++;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
    deg[u]++, deg[v]++;
  }
  int root = max_element(deg + 1, deg + 1 + n) - deg;
  if (deg[root] > 4) {
    printf("NO\n");
    return 0;
  }
  dfs(root, -1, 0, 0, 0, -1);
  printf("YES\n");
  for(int i = 1; i <= n; i++) {
    printf("%I64d %I64d\n", co[i].fi, co[i].se);
  }
  return 0;
}
