#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) {
  if (y < x) x = y;
}
template<typename T, typename U> static void rmax(T &x, U y) {
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

const int N = 1e5 + 10;

ll n, m, r, k;
vector<pair<ll, ll>> x;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> r >> k;
  double ans = 0;
  int cnt = 0;
  if (!((n - 2 * r + 2) <= 0 || (m - 2 * r + 2) <= 0)) x.pb(mp(-r * r, (n - 2 * r + 2) * (m - 2 * r + 2)));
  for (int i = 1; i < r; i++) {
    if (i + r - 1 <= n && (m - 2 * r + 2) > 0) {
      if (n == 2 * i - 1) x.pb(mp(-i * r, (m - 2 * r + 2)));
      else x.pb(mp(-i * r, 2 * (m - 2 * r + 2)));
    }
    if (i + r - 1 <= m && (n - 2 * r + 2) > 0) {
      if (m == 2 * i - 1) x.pb(mp(-i * r, (n - 2 * r + 2)));
      else x.pb(mp(-i * r, 2 * (n - 2 * r + 2)));
    }
  }
  for (int i = 1; i < r; i++) {
    for (int j = 1; j <= i; j++) {
      if (i + r - 1 <= m && j + r - 1 <= n) {

      }
      if (i + r - 1 <= n && j + r - 1 <= m) {

      }
    }
  }
  for (auto t : x) {
    cout << t.first << " " << t.second << endl;
  }
  sort(x.begin(), x.end());
  for (auto t : x) {
    if (t.second <= 0) continue;
    int pen = cnt;
    cnt += t.second;
    if (cnt > k) {
      ans += 1.0 * (k - pen) * (-t.first) / ((n - r + 1) * (m - r + 1));
      break;
    } else {
      ans += 1.0 * (t.second) * (-t.first) / ((n - r + 1) * (m - r + 1));
    }
  }
  cout << fixed << setprecision(14) << ans << endl;
  return 0;
}

