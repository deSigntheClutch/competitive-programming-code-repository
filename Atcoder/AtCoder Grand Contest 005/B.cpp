#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 1;

int n, a[N];
int L[N], R[N];
int stk[N], r;

signed main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      for (int i = 1; i <= n; i++) {
            while (r > 0 && a[stk[r - 1]] > a[i]) {
                  R[stk[r - 1]] = i - 1;
                  r--;
            }
            stk[r++] = i;
      }

      while (r > 0) {
            R[stk[r - 1]] = n;
            r--;
      }

      for (int i = n; i >= 1; i--) {
            while (r > 0 && a[stk[r - 1]] > a[i]) {
                  L[stk[r - 1]] = i + 1;
                  r--;
            }
            stk[r++] = i;
      }

      while (r > 0) {
            L[stk[r - 1]] = 1;
            r--;
      }

      int ans = 0;
      for (int i = 1; i <= n; i++) {
            //cout << i << " " << L[i] << " " << R[i] << endl;
            ans += a[i] * (i - L[i] + 1) * (R[i] - i + 1);
      }

      cout << ans << endl;
      return 0;
}