#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 10;
long long a[N], s[N], f[N];
int n;
 
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  sort(a + 1, a + 1 + n);
  long long mx = 0;
  s[0] = 0, f[0] = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      if(s[j] + a[j] < a[i]) {
        if(f[i] < f[j] + 1) {
          f[i] = f[j] + 1;
          s[i] = s[j] + a[j];
        }
        else if(f[i] == f[j] + 1 && s[i] > s[j] + a[j]) {
          s[i] = s[j] + a[j];
        }
      }
    }
    mx = max(mx, f[i]);
  }
  printf("%I64d\n", mx);
  return 0;
}