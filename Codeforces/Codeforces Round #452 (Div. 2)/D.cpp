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
ll n;
ll nine[N], pw[N];

ll cal(ll x) {
  ll t = x - n;
  if (t >= n) return 0;
  if (t < 1) {
    ll g = x - 1;
    if (g <= 1) return 0;
    else return g / 2;
  } else {
    return (n - t + 1) / 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  nine[0] = 0;
  pw[0] = 1;
  nine[1] = 9;
  pw[1] = 10;
  for (int i = 2; i <= 13; i++) {
    nine[i] = nine[i - 1] * 10 + 9;
    pw[i] = pw[i - 1] * 10;
  }
  int b = 0;
  while (true) {
    if (nine[b + 1] <= n * 2 - 1) b++;
    else break;
  }
  if (b == 0) {
    cout << n*(n - 1) / 2 << endl;
    return 0;
  }
  ll ans = 0;
  for (int bit = 0; bit <= 0; bit++) {
    for (int num = 0; num < 9; num++) {
      ll t = nine[b - bit];
      t += (ll)num * pw[b - bit];
      t += nine[bit] * pw[b - bit + 1];
      ans += cal(t);
    }
  }
  cout << ans << endl;
  return 0;
}

