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
string a, b;

int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  vector<string>v;
  int n = a.length();
  int m = b.length();
  for (int i = 0; i < n; i++) {
    for (int u = 0; u < m; u++) {
      string s1, s2;
      for (int l1 = 0; l1 <= i; l1++) {
        s1 += a[l1];
      }
      for (int l2 = 0; l2 <= u; l2++) {
        s2 += b[l2];
      }
      v.pb(s1+s2);
    }
  }
  sort(v.begin(), v.end());
  cout << v[0]<<endl;
  return 0;
}

