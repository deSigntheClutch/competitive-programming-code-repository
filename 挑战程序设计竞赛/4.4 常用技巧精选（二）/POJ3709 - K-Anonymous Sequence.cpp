#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

const int N = 500000 + 10;
const long long INF = 1e18;
int n, k;
int a[N];
long long dp[N], s[N];

struct Line {
  long long a, b, get(long long x) {
    return a * x + b;
  }
};

struct Convex_Hull_Trick {
  int size;
  Line *hull;

  ConvexHull(int maxSize) {
    hull = new Line[++maxSize], size = 0;
  }
  bool is_bad(long long curr, long long prev, long long next) {
    Line c = hull[curr], p = hull[prev], n = hull[next];
    return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
  }
  void add_line(long long a, long long b) {
    hull[size++] = (Line) {
      a, b
    };
    while (size > 2 && is_bad(size - 2, size - 3, size - 1))
      hull[size - 2] = hull[size - 1], size--;
  }
  long long query(long long x) {
    int l = -1, r = size - 1;
    for(int i = 0; i < 100; i++) {
      int m = (l + r) / 2;
      if (hull[m].get(x) <= hull[m + 1].get(x)) l = m;
      else r = m;
    }
    return hull[r].get(x);
  }
};


int n;
Long sum[N], a[N];
Long ans, dans;
ConvexHull hull;

int main() {
  scanf("%d", &n);

  hull = new ConvexHull(n);
  sum[0] = ans = dans = 0;

  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    ans += a[i] * i;
  }

  hull->size = 0;
  for (int r = 2; r <= n; r++) {
    hull->add_line(r - 1, -sum[r - 2]);
    dans = max(dans, hull->query(a[r]) + sum[r - 1] - a[r] * r);
  }

  hull->size = 0;
  for (int l = n - 1; l >= 1; l--) {
    hull->add_line(-(l + 1), -sum[l + 1]);
    dans = max(dans, hull->query(-a[l]) + sum[l] - a[l] * l);
  }

  printf("%I64d", ans + dans);

  return 0;
}


int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {

    }
  }
  return 0;
}
