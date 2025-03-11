#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll a[N];

int main() {
      int T; cin >> T; while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
            }

            ll ans = accumulate(a+1, a+1+n, 0ll);

            for (int cs = 0; cs < n; cs++) {
                  vector<ll> v;
                  int len = n - cs;
                  if (len == 1) {
                        ans = max((ll)a[1], ans);
                        break;
                  }

                  for (int i = 1; i < len; i++) {
                        v.push_back(a[i + 1] - a[i]);
                  }

                  ans = max(ans, abs(accumulate(v.begin(), v.end(), 0ll)));

                  for (int i = 1; i < len; i++) {
                        a[i] = v[i - 1];
                  }
            }

            cout << ans << endl;
      }
      return 0;
}
