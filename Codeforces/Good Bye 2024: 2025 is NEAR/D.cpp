#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 998244353;

int pow_mod(int u, int v) {
      int res = 1;
      while (v) {
            if (v & 1) res = (long long)res * u % MOD;
            v >>= 1;
            u = (long long)u * u % MOD;
      }
      return res;
}

int n, q;
int a[N], b[N], old_min[N];
int aa[N], bb[N];


void print() {
      for (int i=1; i <=n;i++) {
            cout << a[i] << " ";
      }
      cout << endl;
      for (int i=1; i <=n;i++) {
            cout << b[i] << " ";
      }
      cout << endl;
}
int main() {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout.tie(nullptr);
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> q;
            for (int i = 1; i <= n; i++) {
                  cin >> aa[i];
                  a[i] = aa[i];
            }
            for (int i = 1; i <= n; i++) {
                  cin >> bb[i];
                  b[i] = bb[i];
            }

            sort(a + 1, a + 1 + n);
            sort(b + 1, b + 1 + n);

            int ans = 1;
            for (int i = 1; i <= n; i++) {
                  ans = (long long)ans * min(a[i], b[i]) % MOD;
                  old_min[i] = min(a[i], b[i]);
            }
            cout << ans;


            for (int qq = 0; qq < q; qq++) {
                  int o, x;
                  cin >> o >> x;
                  if (o == 1) {
                        int t = aa[x];
                        aa[x] += 1;
                        int idx = upper_bound(a + 1, a + 1 + n, t) - a - 1;
                        a[idx] += 1;

                        int old_v = old_min[idx];
                        old_min[idx] = min(a[idx], b[idx]);
                        //cout << old_v << " 111 " << old_min[idx] << endl;
                        if (old_v != old_min[idx]) {
                              ans = (long long) ans * pow_mod(old_v, MOD - 2) % MOD;
                              ans = (long long) ans * old_min[idx] % MOD;
                        }
                  } else {
                        int t = bb[x];
                        bb[x] += 1;
                        int idx = upper_bound(b + 1, b + 1 + n, t) - b - 1;
                        b[idx] += 1;

                        int old_v = old_min[idx];
                        old_min[idx] = min(a[idx], b[idx]);
                       // cout << old_v << " 222 " << old_min[idx] << endl;

                        if (old_v != old_min[idx]) {
                              ans = (long long) ans * pow_mod(old_v, MOD - 2) % MOD;
                              ans = (long long) ans * old_min[idx] % MOD;
                        }
                  }
                  cout << " " << ans;
                  //print();
            }

            cout << endl;
      }
      return 0;
}