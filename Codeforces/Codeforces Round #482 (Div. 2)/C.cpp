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

const int N = 3e5 + 10;

int x, y, n;
vector<int> G[N];
int depth[N];
int parent[N];
int sz[N];

void dfs(int u, int v, int fa) {
  depth[v] = u;
  parent[v] = fa;
  sz[v] = 1;
  for (int x : G[v]) {
    if (x == fa) continue;
    dfs(u + 1, x, v);
    sz[v] += sz[x];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >>x >>y;
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    G[a].pb(b);
    G[b].pb(a);
  }
  dfs(0, y, -1);
  int ans = sz[x];
  while(parent[x] != y) {
    x = parent[x];
  }
  cout << (ll)n * (n - 1) - (ll)ans * (n - sz[x]) << endl;
  return 0;
}

