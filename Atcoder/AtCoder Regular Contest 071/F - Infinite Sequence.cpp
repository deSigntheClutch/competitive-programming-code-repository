#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int N = 1e6 + 7;

ll n, f[N];

int main() {
  scanf("%lld", &n);
  f[0] = 1;
  f[1] = n;
  f[2] = (ll)n * n % MOD;
  ll cry = f[0] + n - 1;
  for(int i = 3; i <= n; i++) {
    f[i] = (f[i] + f[i - 1]) % MOD;
    f[i] = (f[i] + cry) % MOD;
    f[i] = ((n - i + 1) * (n) % MOD + f[i]) % MOD;
    cry = ((cry + n - 1) + f[i - 2]) % MOD;
  }
  printf("%lld\n", f[n]);
  return 0;
}
