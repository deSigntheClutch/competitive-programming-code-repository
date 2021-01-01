#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " ";
#define ENDL cerr << "\n";
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void __min(T &x, U y) {
  if (y < x) x = y;
}
template<typename T, typename U> static void __max(T &x, U y) {
  if (x < y) x = y;
}

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e2 + 10;

int n, p;
int w[N], h[N];

void relax(double &a, double b) {
  if (fabs(a - p) > fabs(b - p)) a = b;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> n >> p;
    double lower = 0.0, upper = 0.0;
    double peri = 0.0;
    for (int i = 1; i <= n; i++) {
      cin >> w[i] >> h[i];
      upper = 2 * sqrt(1.0 * w[i] * w[i] + 1.0 * h[i] * h[i]);
      lower = 2.0 * min(w[i], h[i]);
      peri += 2.0 * (w[i] + h[i]);
    }
    double ans = -1e50;
    bool flag = false;
    for (int i = 0; i <= n; i++) {
      if (!(peri + lower * i > 1.0 * p) && !(peri + upper * i < 1.0 * p)) {
        flag = true;
        cout << fixed << setprecision(14) << p << endl;
        break;
      }
      if(peri + lower * i > 1.0 * p) break;
      if (fabs(peri + i * upper - 1.0 * p) > fabs(peri + i * lower - 1.0 * p)) {
        relax(ans, peri + i * lower);
      } else {
        relax(ans, peri + i * upper);
      }
    }
    if (!flag) cout << fixed << setprecision(14) << ans << endl;
  }
  return 0;
}