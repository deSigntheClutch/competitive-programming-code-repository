#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 998244353;

int n;
int T;
int f[N];

int main() {
      f[3] = 1; // 001 | 010 * 2
      f[4] = 3; // 0010 * 3, 0110 * 4 , 1010 * 4
      int presum = 2 + 11;
      for (int i = 5; i < N; i++) {
            f[i] = (presum + 1) % MOD;
            presum = (presum + (long long)i * f[i] % MOD - 1 + MOD) % MOD;
      }

      cin >> T;

      while (T--) {
            cin >> n;
            int ans = 1;
            for (int i = 3; i <= n; i++) {
                  ans = (ans + f[i]) % MOD;
            }
            cout << ans << endl;
      }
}
// 0, 1, 2, 5, 19, 102, 682