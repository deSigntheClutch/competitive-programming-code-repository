#include <bits/stdc++.h>
using namespace std;

const long long INF = 1E18 + 10;

long long n, a;

bool check(long long u, int len) {
  if(u < len) return false;
  long long tp = u / len, tmp = 1;
  for (int i = 1; i <= len; i++) {
    if (i <= u % len) {
      if (INF / tmp < tp + 1) return true;
      tmp *= (tp + 1);
    } else {
      if (INF / tmp < tp) return true;
      tmp *= tp;
    }
  }
  return tmp >= n;
}

int main() {
  cin >> n >> a;
  long long ans = INF;
  for (int i = 1; i <= 44; i++) {
    long long l = 1, r = INF, md;
    for (int cs = 0; cs < 66; cs++) {
      md = (l + r) >> 1;
      if (check(md, i)) r = md;
      else l = md + 1;
    }
    ans = min(ans, md + a * (i - 1));
  }
  cout << ans << endl;
  return 0;
}
