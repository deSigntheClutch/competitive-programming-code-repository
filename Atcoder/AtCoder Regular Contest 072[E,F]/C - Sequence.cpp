#include <bits/stdc++.h>
using namespace std;

const long long INF = 9e18;
const int N = 1e5 + 10;

long long sum[N], a[N];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i - 1];
  }
  long long ans = INF;
  long long a1 = INF, a2 = -INF;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      a1 = min(a1, sum[i]);
    } else {
      a2 = max(a2, sum[i]);
    }
  }
  ans = min(ans, max(0ll, 1 - a1) + max(a2 + 1 + max(0ll, 1 - a1), 0ll));
  a1 = INF, a2 = -INF;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      a2 = max(a2, sum[i]);
    } else {
      a1 = min(a1, sum[i]);
    }
  }
  printf("%lld %lld\n", a2, a1);
  ans = min(ans, max(0ll, 1 - (a1 - max(a2 + 1, 0ll))) + max(a2 + 1, 0ll));
  printf("%lld\n", ans);
  return 0;
}

/*
-1 3 6 8 3 7

*/

-1 3 -1 1
