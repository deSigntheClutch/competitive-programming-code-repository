#include <bits/stdc++.h>

typedef long long Int;

using namespace std;


const Int N = 4e5 + 5;
const Int MOD = 1e9 + 7;

Int n;
string s;
Int ans[N], p[N];

int main() {
      cin >> n >> s;

      p[1] = 1;
      for (Int i = 2; i <= n; i++) {
            p[i] = i * p[i - 1] % MOD;
      }

      Int cur = 0;
      bool flag = false;
      for (Int i = 1; i <= 2 * n; i++) {
            char c = s[i - 1];
            if (c == 'W') {
                  if (cur & 1) {
                        ans[i] = 1;
                        cur += 1;
                  } else {
                        if (cur > 0) {
                              ans[i] = -1;
                              cur -= 1;
                        } else {
                              flag = true;
                        }
                  }
            } else {
                  if (cur % 2 == 0) {
                        ans[i] = 1;
                        cur += 1;
                  } else {
                        if (cur > 0) {
                              ans[i] = -1;
                              cur -= 1;
                        } else {
                              flag = true;
                        }
                  }
            }
      }

      Int sum = 0;
      for (Int i = 1; i <= 2 * n; i++) {
            //cout << ans[i] << " ";
            sum += ans[i];
            flag |= (ans[i] == 0);
      }

      if (flag || sum != 0) {
            cout << 0 << endl;
            return 0;
      }

      Int cnt = 0, res = 1;
      for (Int i = 1; i <= 2 * n; i++) {
            if (ans[i] == -1) {
                  res = cnt * res % MOD;
                  cnt -= 1;
            } else {
                  cnt += 1;
            }
            //cout << res << endl;
      }
      cout << res * p[n] % MOD << endl;
      return 0;
}