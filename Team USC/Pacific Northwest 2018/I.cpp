#include <bits/stdc++.h>
using namespace std;
#define empty mnaskdnasko

const int N = 2e5 + 1;
const int M = 1e2 + 1;

int n, m;
int a[N];
long long dp[M][N];
long long pref[N], suff[N];
int empty[N];
long long fwt[N];

inline void relax(long long& a, long long v) {
    if (a < v) a = v;
}

struct Line
{
      long long a, b;
      long long get(long long x) {
            return a * x + b;
      }
};

struct ConvexHull
{
      int size;
      Line hull[N];

      ConvexHull() {
            size = 0;
      }

      bool is_bad(long long curr, long long prev, long long next) {
            Line c = hull[curr], p = hull[prev], n = hull[next];
            return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
      }

      void add_line(long long a, long long b) {
            hull[size++] = (Line)
            {
                  a, b
            };
            while (size > 2 && is_bad(size - 2, size - 3, size - 1))
                  hull[size - 2] = hull[size - 1], size--;
      }

      long long query(long long x) {
            int l = -1, r = size - 1;
            while (r - l > 1)
            {
                  int m = (l + r) / 2;
                  if (hull[m].get(x) <= hull[m + 1].get(x))
                        l = m;
                  else
                        r = m;
            }
            return hull[r].get(x);
      }
};

ConvexHull hull = ConvexHull();

void add(int x) {
    while (x <= m) {
        fwt[x] += 1;
        x += x & -x;
    }
}

long long get(int x) {
    long long res = 0;
    while (x) {
        res += fwt[x];
        x -= x & -x;
    }
    return res;
}

long long cal() {
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) continue;
        res += get(m) - get(a[i]);
        add(a[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        empty[i] = empty[i - 1] + (a[i] == 0);
    }
    for (int i = m; i >= 1; i--) {
        long long carry = 0;
        for (int j = 1; j <= n; j++) {
            carry += (i < a[j] && a[j] != 0);
            if (a[j] == 0) pref[j] = pref[j - 1] + carry;
            else pref[j] = pref[j - 1];
        }
        carry = 0;
        for (int j = n; j >= 1; j--) {
            carry += (i > a[j] && a[j] != 0);
            if (a[j] == 0) suff[j] = suff[j + 1] + carry;
            else suff[j] = suff[j + 1];
        }
        hull.size = 0;
        hull.add_line(0, 0);
        for (int j = 1; j <= n; j++) {
            if (a[j] != 0) {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            dp[i][j] = max(dp[i + 1][j], pref[j] - suff[j + 1] + hull.query(empty[j]));
            hull.add_line(empty[j], dp[i + 1][j] + suff[j + 1] - pref[j] - empty[j] * empty[j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        relax(ans, dp[i][n]);
    }
    cout << ans + cal() << endl;
    return 0;
}