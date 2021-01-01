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

const int N = 1e3 + 10;

int c;
int a[N];
char b[N][N];

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> c;
    for (int i = 1; i <= c; i++) {
      cin >> a[i];
    }
    if (a[1] == 0 || a[c] == 0) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    int bound = 1;
    for (int i = 1; i < N; i++) {
      for (int j = 1; j <= c; j++) {
        b[i][j] = '.';
      }
    }
    int X = 1;
    for (int i = 1; i <= c; i++) {
      int l = bound;
      bound += a[i];
      if (a[i] == 0) continue;
      for (int j = l; j < bound; j++) {
        if (j == i) continue;
        if (j < i) {
          int cnt = 1;
          for (int k = j; k < i; k++) {
            //cout << j << k;
            if (k == 1 || k == c) break;
            b[cnt++][k] = '\\';
            X = max(X, cnt);
          }
        } else {
          int cnt = 1;
          for (int k = j; k > i; k--) {
            if (k == 1 || k == c) break;
            b[cnt++][k] = '/';
            X = max(X, cnt);
          }
        }
      }
    }
    cout << X << endl;
    for (int i = 1; i <= X; i++) {
      for (int j = 1; j <= c; j++) {
        cout << b[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}

/*

3
4
1 1 1 1
3
0 2 1
1
6
3 0 0 2 0 1

*/
