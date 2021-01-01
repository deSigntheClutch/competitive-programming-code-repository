#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e3 + 10;

int k, p1, p2, pa, pb;
int f[N][N];

int pow_mod(int u, int x) {
  int res = 1;
  while (x) {
    if (x & 1) res = (ll)res * u % MOD;
    x >>= 1;
    u = (ll)u * u % MOD;
  }
  return res;
}

int dfs(int u, int v) {
  if (f[u][v] != -1) return f[u][v];
  if (u + v >= k) return f[u][v] = (pow_mod(pb, MOD - 2) - 1 + u + MOD) % MOD;
  return f[u][v] = ((ll)pa * dfs(u + 1, v) % MOD + (ll)pb * (dfs(u, v + u) + u) % MOD) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> k >> p1 >> p2;
  pa = (ll)p1 * pow_mod(p1 + p2, MOD - 2) % MOD;
  pb = (ll)p2 * pow_mod(p1 + p2, MOD - 2) % MOD;
  memset(f, -1, sizeof f);
  cout << dfs(1, 0) << endl;
  return 0;
}

