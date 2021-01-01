#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

int n, p, k;
int r, s, solved[2][N];
int f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> p >> k;
  cin >> r;
  for(int t, i = 1; i <= r; i++) {
    cin >> t;
    solved[0][t] = 1;
  }
  cin >> s;
  for(int t, i = 1; i <= s; i++) {
    cin >> t;
    solved[1][t] = 1;
  }
  for(int i = 1; i <= n; i++) {
    solved[0][i] += solved[0][i - 1];
    solved[1][i] += solved[1][i - 1];
  }
  memset(f, -1, sizeof f);
  f[0][p] = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 1; j <= p; j++) {
      if(f[i][j] == -1) continue;
      for(int len = 1; len <= k; len++) {
        f[i + len][j - 1] = max(f[i + len][j - 1], f[i][j] + max(solved[0][i + len] - solved[0][i], solved[1][i + len] - solved[1][i]));
      }
      f[i + 1][j] = max(f[i][j], f[i + 1][j]);
    }
  }
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= p; j++) {
      printf("%d ", f[i][j]);
    }
    printf("\n");
  }
  return 0;
}

