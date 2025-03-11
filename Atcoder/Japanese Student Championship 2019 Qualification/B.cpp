#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 1;
const int MOD = 1e9 + 7;

int a[N];
int n, k;

int powMod(int u, int v, int mod) {
      int res = 1;
      while (v) {
            if (v & 1) res = (long long)res * u % mod;
            v >>= 1;
            u = (long long)u * u % mod;
      }
      return res;
}


int main() {
      cin >> n >> k;

      long long inv = 0, iv = 0;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int j = 1; j < i; j++) {
                  if (a[j] > a[i]) {
                        inv += 1;
                  }
            }
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  if (i == j) continue;
                  if (a[j] > a[i]) {
                        iv += 1;
                  }
            }
      }

      inv = inv * (long long)k % MOD;
      long long tmp = (long long)iv * k % MOD * (k - 1) % MOD * powMod(2, MOD - 2, MOD) % MOD;
      cout << (inv + tmp) % MOD << endl;
      return 0;
}