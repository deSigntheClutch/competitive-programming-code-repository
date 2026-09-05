#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 10007;

int a, b, k, n, m;

int pow_mod(int u, int x) {
      int res = 1;
      while (x) {
            if (x & 1) res = (long long)res * u % MOD;
            x >>= 1;
            u = (long long)u * u % MOD;
      }
      return res;
}


int main() {
      cin >> a >> b >> k >> n >> m;

      int ans = 1;
      for (int i = 0; i < n; i++) {
            ans = (long long) ans * a % MOD;
      }

      for (int i = 0; i < m; i++) {
            ans = (long long) ans * b % MOD;
      }

      for (int i = n + 1; i <= k; i++) {
            ans = (long long) ans * i % MOD;
      }

      for (int i = 1; i <= k - n; i++) {
            ans = (long long) ans * pow_mod(i, MOD - 2) % MOD;
      }

      cout << ans << endl;
      return 0;
}