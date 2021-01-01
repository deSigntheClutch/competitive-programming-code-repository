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
int m, n;
int p[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> m >> n;
  for (int i = 0; i < n; i++){
    int ans;
    cout << 1 << endl;
    fflush(stdout);
    cin >> ans;
    if(ans == -2) return 0;
    if(ans == 1) {
      p[i] = 1;
    } else if(ans == 0) {
      exit(0);
    } else {
      p[i] = 0;
    }
  }
  int l = 2, r = m, md;
  for (int i = 0; i < 30; i++){
    int ans;
    md = (l + r) >> 1;
    cout << md << endl;
    fflush(stdout);
    cin >> ans;
    if(ans == -2) return 0;
    if(p[i%n] == 0) ans *= -1;
    if(ans == 1) l = md + 1;
    else if(ans == 0) exit(0);
    else r = md - 1;
  }
  return 0;
}

