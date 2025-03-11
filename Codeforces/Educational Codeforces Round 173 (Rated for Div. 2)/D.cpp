#include <bits/stdc++.h>
#include <numeric>

using namespace std;

const long long INF = 2e18 + 12;

long long l, r, g;
int T;


int main() {
      cin >> T;
      while (T--) {
            cin >> l >> r >> g;

            long long a = (l / g) * g;
            if (a < l) a += g;

            long long b = (r / g) * g;
            //cout << a << " " << b << endl;
            long long ans = -INF, ansa, ansb;

            int cntX = 0;
            for (long long x = a; ; x += g) {
                  cntX += 1;
                  if (x > b || cntX > 20) break;

                  int cntY = 0;
                  for (long long y = b;; y -= g) {
                        cntY += 1;
                        if (y < a || cntY > 20) break;

                        if (x > y || x > b || y < a) continue;

                        if (std::gcd(x, y) == g) {
                              if (y - x > ans) {
                                    ans = y - x;
                                    ansa = x;
                                    ansb = y;
                              }
                        }
                  }
            }

            if (ans == -INF) cout << -1 << " " << -1 << endl;
            else cout << ansa << " " << ansb << endl;
      }
      return 0;
}
