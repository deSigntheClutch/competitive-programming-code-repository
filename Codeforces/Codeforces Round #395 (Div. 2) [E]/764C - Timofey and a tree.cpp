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
int col[N], f[N], g[N], siz[N], ft[N];
int n;

void dfs(int u, int fa) {
  ft[u] = fa;
  siz[u] = 1;
  if (G[u].size() == 1 && G[u][0] == fa) {
    f[u] = col[u];
    return ;
  }
  map<int, int> mp;
  mp.clear();
  mp[col[u]] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs(v, u);
    mp[f[v]]++;
    siz[u] += siz[v];
  }
  int sz = mp.size();
// printf("%d: %d %d\n", u, sz);
  if (mp.size() >= 2 || mp.count(-1) > 0) f[u] = -1;
  else f[u] = mp.begin()->first;
}

void dfs1(int u, int fa) {
  if (f[u] != -1) {
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (v == fa) continue;
      if (u == 1) g[v] = f[u];
      else {
        if (g[u] == f[u]) g[v] = f[u];
        else g[v] = -1;
      }
    }
  } else {
    map<int, int> mp;
    mp.clear();
    mp[col[u]] = 1;
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (v == fa) continue;
      mp[f[v]]++;
    }
    int sz = mp.size();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i];
      if (v == fa) continue;
      int judge = sz;
      mp[f[v]]--;
      if (mp[f[v]] == 0) judge--;
      int nu = 0;
      if ((mp.count(-1) == 0 || mp[-1] == 0) && judge == 1) {
        for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
          if(it->first != -1){
            nu = it->first;
            break;
          }
        }
      } else nu = -1;
      if (u == 1) {
        g[v] = nu;
      } else {
        if (nu == g[u]) g[v] = nu;
        else g[v] = -1;
      }
    }
    mp[f[v]]--;
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
  }
}

bool check(int u) {
  set<int> s;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == ft[u]) continue;
    s.insert(f[v]);
  }
  if (u != 1) s.insert(g[u]);
  if (s.find(-1) == s.end()) return true;
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", col + i);
  }
  dfs(1, -1);
  dfs1(1, -1);
  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      puts("YES");
      printf("%d\n", i);
      return 0;
    }
  }
  puts("NO");
  return 0;
}
