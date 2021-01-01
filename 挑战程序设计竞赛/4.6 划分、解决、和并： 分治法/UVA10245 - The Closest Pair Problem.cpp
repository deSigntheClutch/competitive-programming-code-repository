#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> P;
const double INF = 1e9;
const double eps = 1e-7;

int sgn(double u) {
  if(u > eps) return 1;
  else if(u < -eps) return -1;
  else return 0;
}

bool cmp_y(P u, P v) {
  return sgn(u.second - v.second) < 0;
}

int n;
P a[10005];

double closest_pair(P *a, int n) {
  if(n <= 1) return INF;
  int m = n / 2;
  double x = a[m].first;
  double d = min(closest_pair(a, m), closest_pair(a + m, n - m));
  sort(a, a + n, cmp_y);
  vector<P> b;
  for(int i = 0; i < n; i++) {
    if(sgn(fabs(a[i].first - x) - d) >= 0) {
      continue;
    }
    for(int j = 0; j < b.size(); j++) {
      double dx = a[i].first - b[b.size() - j - 1].first;
      double dy = a[i].second - b[b.size() - j - 1].second;
      if(sgn(dy - d) >= 0) break;
      d = min(d, sqrt(dx * dx + dy * dy));
    }
    b.push_back(a[i]);
  }
  return d;
}

int main() {
  ios::sync_with_stdio(0);
  while(~scanf("%d", &n), n) {
    for(int i = 0; i < n; i++) {
      scanf("%lf %lf", &a[i].first, &a[i].second);
    }
    sort(a, a + n);
    double ans = closest_pair(a, n);
    if(sgn(ans - 1e4) >= 0) printf("INFINITY\n");
    else printf("%.4f\n", ans);
  }
  return 0;
}
