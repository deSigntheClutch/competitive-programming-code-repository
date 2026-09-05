#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, x;
ll a[N], sum[N], rsum[N];
bool l[N], r[N];


int main() {
      int T; cin >> T; while (T--) {
            cin >> n >> x;

            for (int i = 0; i <= n + 2; i++) {
                  l[i] = 0;
                  r[i] = 0;
                  sum[i] = 0;
                  rsum[i] = 0;
                  a[i] = 0;
            }

            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  sum[i] = sum[i - 1] + a[i];
            }
            for (int i = n; i >= 1; i--) {
                  rsum[i] = rsum[i + 1] + a[i];
            }
            multiset<ll> ms;

            for (int i = n; i >= 1; i--) {
                  ms.insert(sum[i] - a[i + 1]);

                  if (i < n) {
                        if (*ms.begin() >= sum[i - 1]) {
                              r[i] = 1;
                              cout << i << " r = ok " << endl;
                        } else {
                              r[i] = 0;
                        }
                  } else {
                        r[i] = 1;
                  }
            }

            ms.clear();
            for (int i = 1; i <= n; i++) {
                  if (i > 1) {
                        if (*ms.begin() >= rsum[i + 1]) {
                              l[i] = 1;
                              cout << i << " l = ok " << endl;

                        } else {
                              l[i] = 0;
                        }
                  } else {
                        l[i] = 1;
                  }
                  ms.insert(rsum[i] - a[i - 1]);
            }

            int ans = 0;
            for (int i = 1; i <= n; i++) {
                  if (r[i] && l[i]) cout << i << endl;
                  ans += (l[i] && r[i]);
            }

            cout << ans << endl;
      }
      return 0;
}
