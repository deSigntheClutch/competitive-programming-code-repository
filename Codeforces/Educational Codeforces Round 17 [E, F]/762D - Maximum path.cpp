#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug0(x) printf("! %d\n", x);
#define debug1(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define nono(x, ite) for(__typeof((x).begin()) (ite)=(x).begin();(ite)!=(x).end();(ite++))
#define nl puts("");

typedef long long ll;

const int N = 1e5 + 10;
const ll INF = 1e18 + 10;

int n;
ll a[3][N], f[3][N][2][2][2], g[3][N], sum[N];

void update(int i, int j) {
  ll res = -INF;
  for (int u = 0; u < 2; u++) {
    for (int v = 0; v < 2; v++) {
      for (int w = 0; w < 2; w++) {
        res = max(res, f[i][j][u][v][w]);
      }
    }
  }
  g[i][j] = res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%I64d", &a[i][j]);
    }
  }
  for (int v = 1; v <= n; v++) {
    sum[v] = sum[v - 1] + a[0][v] + a[1][v] + a[2][v];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = -INF;
      for (int u = 0; u < 2; u++) {
        for (int v = 0; v < 2; v++) {
          for (int w = 0; w < 2; w++) {
            f[i][j][u][v][w] = -INF;
          }
        }
      }
    }
  }
  f[0][1][1][0][0] = g[0][1] = a[0][1];
  f[1][1][1][1][0] = g[1][1] = a[1][1] + a[0][1];
  f[2][1][1][1][1] = g[2][1] = a[0][1] + a[1][1] + a[2][1];
  for (int i = 2; i <= n; i++) {
    f[0][i][1][0][0] = a[0][i] + g[0][i - 1];
    f[0][i][1][1][0] = a[0][i] + a[1][i] + g[1][i - 1];
    f[0][i][1][1][1] = a[0][i] + a[1][i] + a[2][i] + g[2][i - 1];
    f[1][i][0][1][0] = a[1][i] + g[1][i - 1];
    f[1][i][1][1][0] = a[0][i] + a[1][i] + g[0][i - 1];
    f[1][i][0][1][1] = a[1][i] + a[2][i] + g[2][i - 1];
    f[2][i][0][0][1] = a[2][i] + g[2][i - 1];
    f[2][i][0][1][1] = a[1][i] + a[2][i] + g[1][i - 1];
    f[2][i][1][1][1] = a[0][i] + a[1][i] + a[2][i] + g[0][i - 1];
    if (i >= 2) {
      f[2][i][1][1][1] = max(f[2][i][1][1][1], f[0][i - 1][1][0][0] + sum[i] - sum[i - 2] - a[0][i - 1]);
      if (i >= 3) {
        f[0][i][1][1][1] = max(f[0][i][1][1][1], f[2][i - 1][0][0][1] + sum[i] - sum[i - 2] - a[2][i - 1]);
      }
    }
    update(0, i), update(1, i), update(2, i);
  }
  printf("%I64d\n", g[2][n]);
  return 0;
}

