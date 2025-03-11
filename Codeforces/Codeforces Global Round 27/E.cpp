#include <iostream>
#include <algorithm>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const double INF = 9e18;

long long x, y, z, k;

long long cal(long long d, long long val, long long health) {
      return x * (val - d * k) + y * ((health + (val - 1)) / val);
}

long long ternary_search(long long d) {
      long long l = d * k + 1, r = (d + 1) * k;
      long long healthLeft = z - d * (d + 1) / 2 * k;
      long long res = INF;

      for (long long i = l; i <= r; i++) {
            //cout << i << " " << cal(d, i, healthLeft) << endl;
            res = min(res, cal(d, i, healthLeft));
            if (i > l) {
                  if ( (healthLeft + (i - 1)) / i == (healthLeft + i) / (i + 1) ) {
                        long long t = (healthLeft + (i - 1)) / i;
                        if (t > 1) i = healthLeft / (t - 1) - 1;
                        else {
                              break;
                        }
                  }
            }
      }
      return res;
}


int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> x >> y >> z >> k;
            long long ans = 9e18 + 1, cur_cost = 0;

            for (long long d = 0; d < (long long)(3e4 + 10); d++) {
                  if (z - d * (d + 1) / 2 * k < 0) break;

                  ans = min(ans, ternary_search(d) + cur_cost);
                  if (d > 0)
                        ans = min(ans, cal(d, d * k, z - d * (d + 1) / 2 * k) + cur_cost);
                  cur_cost += k * x + y;
            }
            cout << ans << endl;
      }
      return 0;
}