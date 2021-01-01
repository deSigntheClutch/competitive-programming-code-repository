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

const int N = 2E5 + 10;
const ll INF = 9e18 + 10;

struct edge {
  int to;
  ll str, val;
  edge(int a, ll b, ll c) {
    to = a, str = b, val = c;
  }
};

bool flag = false;
vector<edge> G[N];
ll sumWeight[N], fWeight[N], fStrength[N];
ll target, fa[N], mxWeight[N], mnWeight[N];
int n;

void dfs0(int u, int f) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].to;
    if (v == f) continue;
    fWeight[v] = G[u][i].val, fStrength[v] = G[u][i].str;
    dfs0(v, f);
    ll nu = max(1, fWeight[v] - (fStrength[v] - mnWeight[v]));
    mnWeight[u] += mnWeight[v] + nu;
  }
  if (mnWeight[u] > fStrength[u]) {
    flag = true;
  }
}

void dfs1(int u, int f) {
  fa[u] = f;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].to;
    if (v == f) continue;
    dfs1(v, u);
    sumWeight[u] += fWeight[v] + sumWeight[v];
    mxWeight[u] += mxWeight[v];
  }
  mxWeight[u] = min(mxWeight[u], fStrength[u]);
}

void solve(int u, int f, ll t) {

  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].to;
    if (v == f) continue;
    dfs1(v, u);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    ll p, w;
    scanf("%d%d%I64d%I64d", &u, &v, &w, &p);
    G[u].pb(edge(v, p, w));
    G[v].pb(edge(u, p, w));
  }
  fStrength[1] = INF;
  dfs0(1, -1);
  if (flag) {
    printf("-1\n");
    return 0;
  }
  dfs1(1, -1);
  for(int i = 0; i < G[1].size(); i++) {
    solve(G[1][i], 1, sumWeight[G[1][i]] - fWeight[G[1][i]]);
  }
  return 0;
}
