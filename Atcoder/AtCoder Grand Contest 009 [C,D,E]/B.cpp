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

const int N = 1e5 + 10;
vector<int> G[N];
int sz[N];
int n;

void dfs(int u, int f) {
  if (G[u][0] == f && G[u].size() == 1) {
    return ;
  }
  sz[u] = 1;
  vector<int> v;
  for (int i = 0; i < G[u].size(); i++) {
    if (G[u][i] == f)continue;
    dfs(G[u][i], u);
    v.pb(sz[G[u][i]]);
  }
  sort(v.begin(), v.end());
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    res = max(res, v[i] + (int)v.size() - 1 - i);
  }
  sz[u] += res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int t;
    scanf("%d", &t);
    G[t].pb(i + 1);
    G[i + 1].pb(t);
  }
  dfs(1, -1);
  int ans = 1;
  ans = max((int)G[1].size(), ans);
  ans = max(sz[1], ans);
  printf("%d\n", ans);
  return 0;
}

