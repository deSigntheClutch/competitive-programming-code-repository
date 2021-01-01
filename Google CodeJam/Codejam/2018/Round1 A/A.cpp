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

const int N = 1e2 + 10;

int a[N][N];
char s[N][N];
int sumV[N];
int n, m;
int h, v;

int main() {
  int T;
  scanf("%d", &T);
  for (int cs = 1; cs <= T; cs++) {
    printf("Case #%d: ", cs);
    scanf("%d%d%d%d", &n, &m, &h, &v);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s[i][j] == '.') a[i][j] = 0;
        else a[i][j] = 1, cnt++;
      }
    }
    h++;
    v++;
    if(cnt % h || cnt % v) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    bool flag = false;
    int cur = 0;
    vector<int> cut1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cur += a[i][j];
      }
      if(cur == cnt / h) {
        cur = 0;
        cut1.push_back(i);
      } else if (cur > cnt / h) {
        flag = true;
      }
    }
    cur = 0;
    vector<int> cut2;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cur += a[j][i];
      }
      if(cur == cnt / v) {
        cur = 0;
        cut2.push_back(i);
      } else if (cur > cnt / v) {
        flag = true;
      }
    }
    int each = (cnt) / (v * h);
    int s = 1, e = 1;
    for (int x : cut1) {
      for(int y : cut2) {
        int cu = 0;
        for(int i = s; i <= x; i++) {
          for(int j = e; j <= y; j++) {
            cu += a[i][j];
          }
        }
        if(cu != each) flag = true;
        e = y + 1;
      }
      s = x + 1;
      e = 1;
    }
    if(flag) printf("IMPOSSIBLE\n");
    else printf("POSSIBLE\n");
  }
  return 0;
}

/*

6
3 6 1 1
.@@..@
.....@
@.@.@@

*/
