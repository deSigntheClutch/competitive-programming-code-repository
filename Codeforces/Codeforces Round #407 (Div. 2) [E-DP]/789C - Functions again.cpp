#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;

ll a[N], b[N];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  for (int i = 1 ; i < n; i++) {
    b[i] = abs(a[i] - a[i + 1]);
  }
  n--;
  ll ans = *max_element(b + 1, b + 1 + n), sum = 0;
  // case1
  for (int i = 1; i <= n; i++) {
    if (i & 1) a[i] = b[i];
    else a[i] = -b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sum + a[i] <= 0) sum = 0;
    else sum += a[i];
    ans = max(ans, sum);
  }

  // case2
  sum = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) a[i] = -b[i];
    else a[i] = b[i];
  }
  for (int i = 1; i <= n; i++) {
    if (sum + a[i] <= 0) sum = 0;
    else sum += a[i];
    ans = max(ans, sum);
  }
  printf("%I64d\n", ans);
  return 0;
}
/*

50
-5 -9 0 44 -10 37 34 -49 11 -22 -26 44 8 -13 23 -46 34 12 -24 2 -40 -15 -28 38 -40 -42 -42 7 -43 5 2 -11 10 43 9 49 -13 36 2 24 46 50 -15 -26 -6 -6 8 4 -44 -3

*/

