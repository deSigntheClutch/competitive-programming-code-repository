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
int a[N];
set<int> s;
bool vis[N];
bool prime[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= k;
    s.insert(a[i]);
  }
  vis[0] = 1;
  for (int x : s) {
    if (__gcd(x, k) == 1) {
      cout << k << endl;
      for (int i = 0; i < k; i++) {
        cout << i << " ";
      }
      cout << endl;
      return 0;
    } else {
      int tmp = (2 * x) % k;
      vis[tmp] = 1;
      vis[x] = 1;

      for (int t = 0; ;t++) {
        if (tmp == x) break;
        tmp = (tmp + x) % k;
      }
    }
  }
  int cnt = 0;
  for (int i = 0; i < k; i++) {
    if(vis[i] == 1) cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < k; i++) {
    if(vis[i] == 1) cout << i << " ";
  }
  cout << endl;
  return 0;
}

