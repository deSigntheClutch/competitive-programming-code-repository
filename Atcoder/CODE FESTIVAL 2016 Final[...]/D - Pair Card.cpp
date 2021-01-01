#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int n, m;
int _pair[N], mod[N], a[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    mod[a[i] % m]++;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int pt = i;
    while (a[pt] == a[i] && pt <= n) pt++;
    _pair[a[i] % m] += (pt - i) / 2;
    i = pt - 1;
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    if (i > m - i) break;
    int u = mod[i] - _pair[i] * 2, v = mod[m - i] - _pair[m - i] * 2;
    if (i == m - i || i == 0) {
      ans += _pair[i] + u / 2;
    } else {
      int mu = mod[i], mv = mod[m - i];
      if (u < v) swap(u, v), swap(mu, mv);
      ans += v + min(u - v, mv - v) + (mv - v - min(u - v, mv - v)) / 2 + (mu - u) / 2;
    }
  }
  printf("%d\n", ans);
  return 0;
}
