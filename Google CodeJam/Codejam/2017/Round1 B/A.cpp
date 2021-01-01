#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

const int N = 1e3 + 10;

int D, n;
pair<int, int> a[N];
double f[N];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cs = 1; cs <= T; cs++) {
    printf("Case #%d: ", cs);
    scanf("%d %d", &D, &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i].fi, &a[i].se);
      f[i] = 1.0 * (D - a[i].fi) / a[i].se;
    }
    printf("%.7f\n", D / *max_element(f + 1,f + 1 + n));
  }
  return 0;
}

