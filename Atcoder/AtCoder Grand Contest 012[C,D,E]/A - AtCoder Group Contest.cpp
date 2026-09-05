#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[3 * N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3 * n; i++) {
    scanf("%d", a + i);
  }
  sort(a, a + 3 * n);
  int pt = 3 * n - 2;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[pt];
    pt -= 2;
  }
  printf("%lld\n", ans);
  return 0;
}

