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

const int N = 3e3 + 10;

int n;
int a[N];
int b[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for(int i=1;i<=n;i++)cin >> a[i];
  for(int i=1;i<=n;i++)cin >> b[i];
  int ans = 1e9;
  for (int y=2;y<n;y++){
    int cost = b[y];
    int tmp = 1e9;
    for(int j = 1; j < y; j++){
      if(a[j] < a[y]) {
        tmp = min(tmp, b[j]);
      }
    }
    cost += tmp;
    tmp = 1e9;
    for(int j = y + 1; j <= n; j++){
      if(a[j] > a[y]) {
        tmp = min(tmp, b[j]);
      }
    }
    cost += tmp;
    ans = min(cost, ans);
  }
  if(ans >= (int)1e9 -1) ans =-1;
  cout << ans << endl;
  return 0;
}

