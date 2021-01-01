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
const int N = 2e5 + 10;

int n;
int a[N], f[N];
pair<int, int> b[N];
vector<pair<int, pair<int, int>>> Q;

void add(int u) {
  while(u <= n) {
    f[u]++;
    u += u & -u;
  }
}

int get(int u) {
  int res = 0;
  while(u) {
    res += f[u];
    u -= u & -u;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = mp(-a[i], i);
    if (i < n && a[i] > i) {
      Q.pb(mp(i, mp(i + 1, min(a[i], n))));
    }
  }
  int pt = 1;
  long long ans = 0;
  sort(b + 1, b + 1 + n);
  reverse(Q.begin(), Q.end());
  for (auto x : Q) {
    int v = x.fi;
    while(pt <= n && -b[pt].fi >= v) {
        add(b[pt].se);
        pt++;
    }
    ans += get(x.se.se) - get(x.se.fi - 1);
  }
  cout << ans << endl;
  return 0;
}

