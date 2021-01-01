#include <bits/stdc++.h>

#define DB(x) cerr << #x << " = " << (x) << " "
#define ENDL cerr << "\n"
#define FOR(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define DBA(x, a, b) { cerr << #x << " = "; for (int _ = (a); _ <= (b); _++) cerr << x[_] << ' '; ENDL }
#define DBS(x) { cerr << #x << " = "; for (auto _ : x) cerr << _ << ' '; cerr << endl; }

using namespace std;

template<typename T, typename U> static void rmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void rmax(T &x, U y) { if (x < y) x = y; }

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

int a[N];

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >>k;
  cin >> s;
  for (int i = 0; i < s.length();i++){
    a[i] = (int)(s[i] - 'a') + 1;
  }
  sort(a,a+s.length());
  int ans = 0;
  int cur = -7;
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if(cur + 1 < a[i]) {
      cur = a[i];
      ans += a[i];
      cnt++;
    }
    if(cnt == k) break;
  }
  if(cnt != k) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
