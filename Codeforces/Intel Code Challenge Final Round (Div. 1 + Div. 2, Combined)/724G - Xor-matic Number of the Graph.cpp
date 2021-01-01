#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;
const int SZ = 62;

struct edge {
  int to;
  int64 v;
};

vector<edge> G[N];
vector<int64> cycles;
int n, m, vis[N];
int64 f[N], cnt[SZ][2];

void dfs(int u, int fa, int64 val) {
  for (int i = 0; i < SZ; i++) {
    if (val >> i & 1) cnt[i][1]++;
    else cnt[i][0]++;
  }
  f[u] = val;
  vis[u] = 1;
  for (edge e : G[u]) {
    if(e.to == fa) continue;
    if (vis[e.to]) {
      cycles.push_back(f[u] ^ f[e.to] ^ e.v);
      continue;
    }
    dfs(e.to, u, val ^ e.v);
  }
}

vector<int64> getBasis(vector<int64> v) {
  vector<int64> tmp(SZ, 0), res;
  for(int64 x : v) {
    for(int i = SZ - 1; i >= 0; i--) {
      if(x >> i & 1) {
        if(!tmp[i]) {
          tmp[i] = x;
          break;
        } else {
          x ^= tmp[i];
        }
      }
    }
  }
  for(int i = 0; i < SZ; i++) {
    if(tmp[i]) {
      res.push_back(tmp[i]);
    }
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    int64 l;
    scanf("%d%d%I64d", &u, &v, &l);
    G[u].push_back((edge) {
      v, l
    });
    G[v].push_back((edge) {
      u, l
    });
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    memset(cnt, 0, sizeof cnt);
    cycles.clear();
    dfs(i, -1, 0);
    vector<int64> basis = getBasis(cycles);
    int t = (int)basis.size();
    for(int j = 0; j < SZ; j++) {
      bool flag = false;
      for(int64 x : basis) {
        if(x >> j & 1) {
          flag = true;
        }
      }
      if(flag) ans = (ans + (1ll << j) % MOD * ((cnt[j][0] * cnt[j][1]) % MOD) % MOD * ((1ll << t - 1) % MOD) % MOD) % MOD; // Route 1
      else ans = (ans + (1ll << j) % MOD * ((cnt[j][0] * cnt[j][1]) % MOD) % MOD * ((1ll << t) % MOD) % MOD) % MOD; // Route 1
      if(flag) ans = (ans + (1ll << j) % MOD * ((cnt[j][0] * (cnt[j][0] - 1) / 2 + cnt[j][1] * (cnt[j][1] - 1) / 2) % MOD) % MOD * ((1ll << t - 1) % MOD) % MOD) % MOD; // Route 0
    }
  }
  printf("%d\n", ans);
  return 0;
}

/*

4 4
1 2 0
1 3 1
2 3 1
3 4 0

4 4
1 2 1
1 3 2
2 3 3
3 4 1

*/
