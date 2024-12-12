#include <iostream>
#include <algorithm>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

long long x, y, z, k;

long long cal(long long d, int long long val) {
  //cout << d << " " << val << " " << (x * (val - d * k) + y * (((z - d * (d + 1) / 2 * k) + (val - 1)) / val)) << endl;
  return x * (val - d * k) + y * (((z - d * (d + 1) / 2 * k) + (val - 1)) / val);
}


long long ternary_search(long long d) {
  long long l = d * k + 1, r = (d + 1) * k;
  for (int i = l; i <= r; i++) {
    cout << d << " " <<  i << " " << cal(d, i) << endl;
  }
  for (; r - l > 1; ) {
    long long lmid = (2 * l + r) / 3, rmid = (l + 2 * r) / 3;
    //cout << lmid << " " << rmid << " -- " << l << " " << r << endl;
    if (cal(d, lmid) > cal(d, rmid)) {
      l = lmid + 1;
    } else {
      r = rmid;
    }
  }
  return min(cal(d, l), cal(d, r));
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
      if (d > 0) ans = min(ans, cal(d, d * k) + cur_cost);

      cur_cost += k * x + y;
    }
    cout << ans << endl;
  }
  return 0;
}
