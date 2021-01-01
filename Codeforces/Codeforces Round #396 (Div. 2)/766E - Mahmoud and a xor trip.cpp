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
int a[N], b[N], n;
ll ans, f[2][N], cnt;

void dfs(int u, int fa) {
  ll cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs(v, u);
    cnt1 += f[1][v];
    cnt0 += f[0][v];
  }
  if (b[u] == 1) f[1][u] = 1 + cnt0, f[0][u] = cnt1;
  else f[0][u] = 1 + cnt0, f[1][u] = cnt1;
}

void dfs1(int u, int fa) {
  ll res = 0;
  // Case 1
  res = f[1][u];
  ll cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v =  G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    if (b[u] == 1) {
      res += f[1][v] * cnt1 + f[0][v] * cnt0;
    } else {
      res += f[0][v] * cnt1 + f[1][v] * cnt0;
    }
    cnt1 += f[1][v];
    cnt0 += f[0][v];
  }
  cnt += res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v), G[v].pb(u);
  }
  for (int i = 0; i <= 21; i++) {
    for (int j = 1; j <= n; j++) {
      b[j] = (a[j] >> i & 1);
    }
    dfs(1, -1);
    cnt = 0;
    dfs1(1, -1);
    ans += cnt * (1ll << i);
  }
  printf("%I64d\n", ans);
  return 0;
}
