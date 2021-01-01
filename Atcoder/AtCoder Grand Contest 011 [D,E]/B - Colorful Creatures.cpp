#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];
long long sum[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    sum[i] = (long long)a[i] + sum[i - 1];
  }
  int ans = 0;
  for (int i = n; i >= 1; i--) {
    if (sum[i] * 2 < (long long)a[i + 1]) break;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}

