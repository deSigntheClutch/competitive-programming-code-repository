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
const ll INF = 2e18 + 5;
const int N = 1e3 + 10;

int R, C;
ll B, m[N], s[N], p[N];
ll x[N], ans = INF;
int perm[N];

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> R >> B >> C;
    for (int i = 1; i <= C; i++) {
      cin >> m[i] >> s[i] >> p[i];
    }

    ll l = 1, r = INF, md;
    for (int tt = 0; tt < 70; tt++) {
      md = (l + r) >> 1;
      memset(x, 0, sizeof x);
      for (int i = 1; i <= C; i++) {
        x[i] = min(m[i], max(0ll, (md - p[i]) / s[i]));
      }
      sort(x + 1, x + 1 + C);
      ll y = 0;
      for (int i = C; i > C - R; i--) {
        y += x[i];
      }
      if (y >= B) r = md;
      else l = md + 1;
    }
    cout << md << endl;
  }
  return 0;
}

/*

3
2 2 2
2 1 3
1 1 2
2 3 2
2 1 3
1 1 2
2 3 2
1 1 1
1 1 1

2 2 2
1 2 3
2 1 2
3 4 5
2 3 3
2 1 5
2 4 2
2 2 4
2 5 1

*/
