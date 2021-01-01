#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int n, len;
int g[N], f[N][N], pre[N][N];
int vis[N];

void init() {
  g[0] = 0;
  for (int i = 1;; i++) {
    g[i] = g[i - 1] + i;
    if (g[i - 1] + i > (int)1e7) {
      len = i;
      break;
    }
  }
}

int main() {
  init();
  cin >> n;
  int v = lower_bound(g + 1, g + 1 + len, n) - g;
  int val = g[v] - n;
  f[0][0] = 1;
  for (int i = 1; i <= v; i++) {
    for (int j = 0; j <= val; j++) {
      if (j - i >= 0 && f[i - 1][j - i] == 1) f[i][j] = 1, pre[i][j] = j - i;
      if (f[i - 1][j] == 1) f[i][j] = 1, pre[i][j] = j;
    }
  }
  int pt = v;
  while (pt >= 1) {
    int key = pre[pt][val];
    vis[val - key] = 1;
    pt--, val = key;
  }
  for (int i = 1; i <= v; i++) {
    if (vis[i]) continue;
    printf("%d\n", i);
  }
  return 0;
}


