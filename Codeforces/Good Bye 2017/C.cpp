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

int n, r;
int x[N];
double y[N];

double cal(int u, int v) {
  return y[v] + sqrt(4.0 * r * r - (x[u] - x[v]) * (x[u] - x[v]));
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> r;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  y[1] = r;
  cout<< fixed << setprecision(13);

  cout << r;
  for (int j = 2; j <= n; j++) {
    vector<pair<double, int>> inters;
    for (int i = 1; i < j; i++) {
      if(x[i] - r > x[j] + r || x[i] + r < x[j] - r) continue;
      inters.pb(mp(cal(j, i), i));
    }
    sort(inters.begin(), inters.end());
    if((int)inters.size() == 0) {
        y[j] = r;
        cout << " " << y[j];
        continue;
    }
    y[j] = inters[(int)inters.size() - 1].fi;
    cout << " " << y[j];
  }
  cout << endl;
  return 0;
}

