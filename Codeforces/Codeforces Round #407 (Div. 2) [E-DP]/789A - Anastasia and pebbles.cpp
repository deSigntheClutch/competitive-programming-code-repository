#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N];

int main() {
  scanf("%d%d", &n, &k);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ans += (int)ceil(1.0 * a[i] / k);
  }
  printf("%d\n", (int)ceil(1.0 * ans / 2));
  return 0;
}

