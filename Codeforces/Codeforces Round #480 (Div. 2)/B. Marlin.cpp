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

int n, k;
char s[5][N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  cout << "YES" << endl;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = '.';
    }
  }
  if (k >= 2 * (n - 2) - 1) {
    for (int i = 2; i <= n - 1; i++) {
      s[2][i] = s[3][i] = '#';
    }
    if (k == 2 * (n - 2) - 1) s[2][(n + 1) / 2] = '.';
  } else {
    int x = 2, y = 2;
    for (int i = 1; i <= k / 2; i++) {
      s[x][y] = '#';
      s[x][n - y + 1] = '#';
      y++;
      if(y == (n + 1) / 2) {
        x = 3;
        y = 2;
      }
    }
    if(k&1) s[2][(n + 1) / 2] = '#';
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%c", s[i][j]);
    }
    printf("\n");
  }
  return 0;
}

