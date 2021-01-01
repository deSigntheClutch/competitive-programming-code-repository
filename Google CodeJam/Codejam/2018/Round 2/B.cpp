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

const int N = 5e2 + 10;
int r, b;
int dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    cin >> r >> b;
    int thre = 1, tun = max(r, b);
    for (int i = 1;; i++) {
      if ((i + 1) * i / 2 > tun) {
        thre = i;
        break;
      }
    }
    for (int x = 1; x < 50; x++) {
      int u = 0;
      int v = x;
      for (int t = 1; t <= x + 1; t++) {
        for (int i = r; i >= 0; i--) {
          for (int j = b; j >= 0; j--) {
            if (dp[i][j] != -1) {
              if (i + u <= r && j + v <= b) {
                dp[i + u][j + v] = max(dp[i + u][j + v], dp[i][j] + 1);
              }
            }
          }
        }
        u++;
        v--;
      }
    }
    cout << dp[r][b] << endl;
  }
  return 0;
}


