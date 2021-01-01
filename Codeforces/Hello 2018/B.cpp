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

vector<int> G[N];
bool leaf[N];
int n;
bool flag = false;

void dfs(int u, int f) {
  if (G[u].size() == 0) {
    leaf[u] = 1;
    return ;
  }
  int cnt = 0;
  for (int x : G[u]) {
    if (f == x) continue;
    dfs(x, u);
    cnt += leaf[x];
  }
  if (cnt < 3) flag = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int t;
    cin >> t;
    G[t].pb(i + 2);
  }
  dfs(1, -1);
  if (flag) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}

