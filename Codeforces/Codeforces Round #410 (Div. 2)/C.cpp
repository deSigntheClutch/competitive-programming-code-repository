#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = __gcd(ans, a[i]);
  }
  if (ans != 1) {
    printf("YES\n0\n");
    return 0;
  }
  int make_2 = 0;
  for (int i = 0; i < n; i++) {
    int pt = i;
    if (a[i] % 2 == 0) continue;
    while ((a[pt] & 1) && pt < n) pt++;
    int len = pt - i;
    if(len & 1) make_2 += len / 2 + 2;
    else make_2 += len / 2;
    i = pt - 1;
  }
  printf("YES\n");
  printf("%d\n", make_2);
  return 0;
}


