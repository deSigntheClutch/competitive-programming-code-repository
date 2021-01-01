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

double a[N], b[N];
int n, m;

bool check(double x) {
  for (int i = 0; i < n; i++) {
    double loss1 = (x + m) / a[i];
    x -= loss1;
    if(x < 0) return false;
    double loss2 = (x + m) / b[(i + 1)%n];
    x -= loss2;
    if(x < 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  double l = 0, r = 1e9 + 5, md;
  for (int i = 0; i < 323; i++) {
    md = (l + r) * .5;
    if(check(md)) r = md;
    else l = md;
  }
  if(md > 1000000000.0 + eps) {
    cout << -1 << endl;
  } else {
    cout << fixed << setprecision(14) << md << endl;
  }
  return 0;
}

