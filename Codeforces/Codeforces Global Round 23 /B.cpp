#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int sum[N], a[N];

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  sum[i] = sum[i - 1] + a[i];
            }

            int ans = n;
            for (int i = 0; i <= n; i++) {
                  int l_1 = sum[i];
                  int r_0 = (n - i) - (sum[n] - sum[i]);

                  ans = min(ans, max(l_1, r_0));
            }

            cout << ans << endl;
      }

      return 0;
}