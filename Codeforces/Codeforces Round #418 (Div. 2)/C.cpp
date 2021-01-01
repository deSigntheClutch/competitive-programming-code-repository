#include <bits/stdc++.h>
using namespace std;

const int N = 1500 + 10;

int ans[26][N];
int a[N], sum[N];
char str[N];
int n, Q;

int cal(int v) {
  int ans = 1;
  for(int i = 1; i <= n; i++) {
    int l = 0, r = i - 1, md;
    for(int cs = 0; cs < 13; cs++) {
      md = (l + r) >> 1;
      if((i - md) - (sum[i] - sum[md]) > v) l = md + 1;
      else r = md;
    }
    ans = max(ans, i - md);
  }
  return ans;
}

void init() {
  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == (int)str[j]) a[j] = 1;
      else a[j] = 0;
      sum[j] = sum[j - 1] + a[j];
    }
    for (int j = 1; j <= n; j++) {
      ans[i - 'a'][j] = cal(j);
    }
  }
}

int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  scanf("%d", &Q);
  init();
  for (int i = 0; i < Q; i++) {
    char cha[2];
    int v;
    scanf("%d%s", &v, cha);
    printf("%d\n", ans[cha[0] - 'a'][v]);
  }
  return 0;
}
