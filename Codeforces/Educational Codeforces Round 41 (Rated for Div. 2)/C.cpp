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
const int INF = 1e9 + 7;
const int N = 1e2 + 10;

int n;
string s[4][N];

int check(int id, char type) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0) {
        if (s[id][i][j] != type) res++;
      } else {
        if (s[id][i][j] == type) res++;
      }
    }
  }
  return res;
}

void relax(int &y, int x) {
  if(y > x) y = x;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }
  int ans = INF;
  for (int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
      int cur = check(i, '1') + check(j, '1');
      for(int k = 0; k < 4; k++) {
        if(k == i || k == j) continue;
        cur += check(k, '0');
      }
      relax(ans, cur);
    }
  }
  cout << ans << endl;
  return 0;
}

