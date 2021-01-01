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

const int N = 55 + 10;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

char s[N][N];
char order[123];
int n, m, len;

pair<int, int> find(char u) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == u) {
        return mp(i, j);
      }
    }
  }
}

bool check(vector<int> v) {
  pair<int, int> x = find('S');
  pair<int, int> y = find('E');
  for (int i = 1; i <= len; i++) {
    int tx = x.fi + dx[v[order[i] - '0']];
    int ty = x.se + dy[v[order[i] - '0']];
    if (tx < 0 || tx > n || ty < 0 || ty > m || s[tx][ty] == '#') return false;
    x = mp(tx, ty);
    if(x == y) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  scanf("%s", order + 1);
  len = strlen(order + 1);

  vector<int> perm;
  perm.pb(0);
  perm.pb(1);
  perm.pb(2);
  perm.pb(3);
  int ans = 0;
  do {
    ans += check(perm);
  } while (next_permutation(perm.begin(), perm.end()));
  cout << ans << endl;
  return 0;
}
