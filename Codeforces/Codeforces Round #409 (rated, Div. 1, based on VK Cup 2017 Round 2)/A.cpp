#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-9;

int n, p;
int a[N], b[N];

bool check(double u) {
  double res = 0;
  for (int i = 1; i <= n; i++) {
    res += max(0.0, u * a[i] - b[i]);
  }
  return (u * p - res > -eps);
}

int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", a + i, b + i);
  }
  long long total_use = accumulate(a + 1, a + 1 + n, (long long)0);
  if(p >= total_use) {
    printf("-1\n");
    return 0;
  }
  double l = 0, r = 1e18 + 10, md;
  for (int cs = 0; cs < 500; cs++) {
    md = (l + r) * .5;
    if (check(md)) l = md;
    else r = md;
  }
  printf("%.9f\n", md);
  return 0;
}

