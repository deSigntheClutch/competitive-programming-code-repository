#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int MOD = 998244353;

int n;
int T;
int f[N];

int main() {
      f[4] = 2;
      for (int i = 5; i < N; i++) {
            f[i] = (long long) (i - 1) * f[i - 1] % MOD;
      }

      cin >> T;
      while (T--) {
            cin >> n;
            if (n == 2) {
                  cout << 1 << endl;
            } else if (n == 3) {
                  cout << 2 << endl;
            } else {
                  int ans = (n - 1) + (n - 2);
                  for (int i = 3; i < n; i++) {
                        ans = (ans + f[i]) % MOD;
                  }
                  cout << ans << endl;
            }
      }
}
// 0, 1, 2, 5, 19, 102, 682