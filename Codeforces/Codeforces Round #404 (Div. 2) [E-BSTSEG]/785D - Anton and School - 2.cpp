#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const long long MOD = 1e9 + 7;

int n;
char s[2 * N];
long long fac[2 * N], _inv[2 * N], inv[2 * N];

void init() {
  fac[0] = 1;
  for (int i = 1; i < 2 * N; i++) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  _inv[0] = _inv[1] = 1;
  inv[0] = inv[1] = 1;
  for (int i = 2; i < 2 * N; i++) {
    _inv[i] = ((MOD - MOD / i) * _inv[MOD % i]) % MOD;
    inv[i] = inv[i - 1] * _inv[i] % MOD;
  }
}

long long C(long long u, long long v) {
  long long res = 1;
  res = res * fac[u] % MOD;
  res = res * inv[v] % MOD;
  res = res * inv[u - v] % MOD;
  return res;
}

int main() {
  scanf("%s", s + 1);
  init();
  n = strlen(s + 1);
  long long sum_l = 0, sum_r = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    if (s[i] == ')') sum_r++;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == ')') {
      sum_r--;
      continue;
    }
    ans = (ans + C(sum_l + sum_r, sum_l + 1)) % MOD;
    sum_l++;
  }
  printf("%I64d\n", ans);
  return 0;
}
