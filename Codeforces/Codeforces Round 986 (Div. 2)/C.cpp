#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

int n, m;
ll v, a[N];
ll pref[N], res_pref[N], suf[N], res_suf[N];
ll sum[N];
int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> m >> v;

            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  sum[i] = a[i] + sum[i - 1];
            }

            ll tmp = 0;
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                  tmp += a[i];

                  if (tmp >= v) {
                        cnt += 1;
                        tmp = 0;
                  }

                  pref[i] = cnt;
                  res_pref[i] = tmp;
            }

            tmp = 0, cnt = 0;
            for (int i = n; i >= 1; i--) {
                  tmp += a[i];

                  if (tmp >= v) {
                        cnt += 1;
                        tmp = 0;
                  }

                  suf[i] = cnt;
                  res_suf[i] = tmp;
            }

            int ptr = n;

            while (ptr >= 1 && suf[ptr] < m) ptr -= 1;

            if (ptr == 0) {
                  cout << -1 << endl;
                  continue;
            }

            ll ans = 0;
            for (int i = 1; i <= n; i++) {
                  int cnt_left = pref[i - 1];
                  ll res = res_pref[i - 1];

                  while (ptr <= n && ((cnt_left + suf[ptr] > m) || (cnt_left + suf[ptr] == m && res_suf[ptr] != 0)))
                        ptr += 1;

                  if (cnt_left + suf[ptr] == m)
                        ans = max(ans, res + sum[ptr - 1] - sum[i - 1]);
            }

            cout << ans << endl;
      }
      return 0;
}