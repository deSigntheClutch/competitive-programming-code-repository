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

int n;
int a[N], k;
int group[300];

int ans[N];

int main() {
  ios::sync_with_stdio(false);
  memset(group, -1, sizeof group);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (group[a[i]] != -1) {
      ans[i] = a[i] - group[a[i]];
    } else {
      int bound = max(-1, a[i] - k);
      for (int j = 0; j < k; j++) {
        if(group[a[i] - j] != -1 && group[a[i] - j] > k - 1 - j) {
          bound = a[i] - j;
          break;
        }
      }
      for (int j = bound + 1; j <= a[i]; j++) {
        group[j] = j - 1 - bound;
      }
      ans[i] = a[i] - group[a[i]];
    }
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}

