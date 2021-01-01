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

const int INF = 1E9 + 10;
const int N = 2E5 + 10;

int leave[N];
map<int, int> state[N];
int n, f[N], g[N];
vector<int> G[N];

void dfs1(int u, int fa) {
  if (G[u].size() == 1 && G[u][0] == fa) {
    leave[u] = 1;
  }
  state[u].clear();
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    state[u][f[v]]++;
  }
  if (state[u].size() >= 2 || state[u].begin()->first == -1) {
    f[u] = -1;
  } else {
    if (state[u].size() == 1) f[u] = state[u].begin()->first + 1;
    else f[u] = 0;
  }
}

void dfs2(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    map<int, int> mp = state[u];
    if (mp.size() > 2 || g[u] == -1) {
      g[v] = -1;
      continue;
    }
    mp[f[v]]--;
    int cnt = 0, val = 0;
    for (map<int, int> :: iterator it = mp.begin(); it != mp.end(); it++) {
      if (it->second == 0) {
        continue;
      } else {
        cnt++;
        val = it->first;
      }
    }
    if (cnt == 1 && val != -1) {
      if (g[u] == 0 || g[u] == val + 1) {
        g[v] = val + 2;
      } else {
        g[v] = -1;
      }
    } else if (cnt == 0) {
      g[v] = g[u] + 1;
    } else {
      g[v] = -1;
    }
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs2(v, u);
  }
}

int gen(int u) {
  if (u == 0) return 0;
  if (u & 1) return u;
  else return gen(u / 2);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v);
    G[v].pb(u);
  }
  dfs1(1, -1);
  dfs2(1, -1);
  int ans = n + 10;
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      if (f[i] != -1) ans = min(ans, gen(f[i]));
      continue;
    }
    if (g[i] != -1) {
      state[i][g[i] - 1]++;
      vector<int> nu;
      bool flag = true;
      if(state[i].size() > 3) continue;
      for (map<int, int> :: iterator it = state[i].begin(); it != state[i].end(); it++) {
        if(it->first == -1 && it->second > 0) flag = false;
        if (it->second == 0 || it->first == -1) {
          continue;
        } else {
          if (nu.size() <= 3) {
            nu.pb(it->first);
          }
        }
      }
      if(flag == false) continue;
      if (nu.size() == 3) continue;
      else if (nu.size() == 2) ans = min(ans, gen(nu[0] + nu[1] + 2));
      else if (nu.size() == 1) {
        if (!leave[i]) ans = min(ans, gen(2 * nu[0] + 2));
        else ans = min(ans, gen(nu[0] + 1));
      }
    }
  }
  if (ans == n + 10) puts("-1");
  else printf("%d\n", ans);
  return 0;
}
/*

7
3 8
4 7
1 2
2 3
2 4
4 5

*/
