#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int t[N], n, c, k;

int main() {
  scanf("%d%d%d", &n, &c, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", t + i);
  }
  sort(t + 1, t + 1 + n);
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int pt = i, cnt = 1;
    while(cnt <= c && pt <= n && t[pt] - t[i] <= k) {
      pt++, cnt++;
    }
    ans++;
    i = pt - 1;
  }
  printf("%d\n", ans);
  return 0;
}
