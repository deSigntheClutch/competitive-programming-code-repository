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
const ll INF = 9e18 + 5;
const int N = 1e5 + 10;

ll n;
int k;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  ll a = INF, b, c;
  if (n == 0) {
    cout << 1 << " " << 0 << endl;
    return 0;
  }
  for (int i = 0; i < k; i++) {
    ll tmp;
    cin >> tmp;
    if (tmp > n) continue;
    if (n % tmp < a) {
      a = n % tmp;
      b = n / tmp;
      c = i + 1;
    }
  }
  if (a == INF) {
    cout << 1 << " " << 0 << endl;
    return 0;
  }
  cout << c << " " << b << endl;
  return 0;
}
