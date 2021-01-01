#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

double x[N], y[N];
int n;

double cal(int w, int u, int v) {
  double res = 1e60;
  w %= n;
  if(w == u || w == v) return res;
  res = abs(1.0 * (x[u] - x[w]) * (y[v] - y[w]) - 1.0 * (y[u] - y[w]) * (x[v] - x[w]));
  //printf("%d %d %d %.6f %.6f\n", w, u, v, res, sqrt(1.0 * (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v])));
  return res / sqrt(1.0 * (x[u] - x[v]) * (x[u] - x[v]) + (y[u] - y[v]) * (y[u] - y[v]));
}

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%lf %lf", &x[i], &y[i]);
  }
  double ans = 1e60;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      ans = min(ans, cal(j - 1 + n, i, j) * .5);
      ans = min(ans, cal(i - 1 + n, i, j) * .5);
      ans = min(ans, cal(i + 1, i, j) * .5);
      ans = min(ans, cal(j + 1, i, j) * .5);
    }
  }
  printf("%.9f\n", ans);
  return 0;
}
/*

4
0 0
0 1
1 1
1 0

*/
