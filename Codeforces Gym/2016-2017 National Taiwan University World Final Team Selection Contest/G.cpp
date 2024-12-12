#include "bits/stdc++.h"
 
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
 
const int N = 2E5 + 5;
 
int n, m;
int a[N];
 
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  priority_queue<pair<long long, int>> Q;
  Q.push(mp(-a[1], 1));
  while (m--) {
    auto x = Q.top();
    Q.pop();
    if(m == 0) {
      cout << -x.fi << endl;
      return 0;
    }
    if(x.se + 1 <= n) {
      Q.push(mp(x.fi + a[x.se] - a[x.se + 1], x.se + 1));
      Q.push(mp(x.fi - a[x.se + 1], x.se + 1));
    }
  }
  return 0;
}