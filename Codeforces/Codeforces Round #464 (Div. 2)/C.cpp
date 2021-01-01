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
int a[2 * N], sum[2 * N];
int s, f;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  cin >> s >> f;
  int len = f - s;
  for (int i = 1; i <= 2 * n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  int mx = 0, start_time = 0;
  for (int i = 1; i <= n; i++) {
    int left_bound = i, right_bound = i + len - 1;
    int key = (s - (i - 1) + n) % n;
    if (key == 0) key = n;
    if (sum[right_bound] - sum[i - 1] > mx) {
      mx = sum[right_bound] - sum[i - 1];
      start_time = key;
    } else if (sum[right_bound] - sum[i - 1] == mx && key < start_time) {
      start_time = key;
    }
  }
  cout << start_time << endl;
  return 0;
}

