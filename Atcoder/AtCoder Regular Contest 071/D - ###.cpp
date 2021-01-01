#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for(int j = 0; j < m; j++) {
    scanf("%d", b + j);
  }
  vector<long long> v, u;
  for(int i = 0; i < m - 1; i++) {
    v.push_back(b[i + 1] - b[i]);
  }
  for(int i = 0; i < n - 1; i++) {
    u.push_back(a[i + 1] - a[i]);
  }
  long long ans = 0, cnt = 0, cry = 0;
  for(int i = 0; i < m - 1; i++) {
    cry = (cry + (long long)(i + 1) * (m - 1 - i) % MOD * v[i] % MOD) % MOD;
  }
  for(int i = 0; i < n - 1; i++) {
    ans = (ans + ((long long)(i + 1) * (n - 1 - i) % MOD) * cry % MOD * u[i] % MOD) % MOD;
  }
  printf("%lld\n", ans);
  return 0;
}
