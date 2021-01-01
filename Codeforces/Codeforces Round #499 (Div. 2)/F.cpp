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
#define rson rt << 1 s| 1, mid + 1, right

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

const int N = 1e6 + 5;
vector<int> G[N];
string func[N];
bool cur[N];
bool nece[N];
bool ans[N];
int n;

void dfs1(int u) {
  for (int x : G[u]) {
    dfs1(x);
  }
  if (func[u] == "AND") {
    cur[u] = cur[G[u][0]] & cur[G[u][1]];
  } else if (func[u] == "XOR") {
    cur[u] = cur[G[u][0]] ^ cur[G[u][1]];
  } else if (func[u] == "OR") {
    cur[u] = cur[G[u][0]] | cur[G[u][1]];
  } else if (func[u] == "NOT") {
    cur[u] = cur[G[u][0]] ^ 1;
  } else return;
}

void dfs2(int u) {
  int x, y;
  if (func[u] == "AND") {
    x = G[u][0];
    y = G[u][1];
    if (cur[y] == 1) nece[x] = 1;
    if (cur[x] == 1) nece[y] = 1;
  } else if (func[u] == "XOR") {
    x = G[u][0];
    y = G[u][1];
    nece[x] = 1;
    nece[y] = 1;
  } else if (func[u] == "OR") {
    x = G[u][0];
    y = G[u][1];
    if (cur[y] == 0) nece[x] = 1;
    if (cur[x] == 0) nece[y] = 1;
  } else if (func[u] == "NOT") {
    x = G[u][0];
    nece[x] = 1;
  } else return ;
  for (int x : G[u]) {
    dfs2(x);
  }
}

void dfs3(int u, int v, int depth) {
  for (int x : G[u]) {
    dfs3(x, v + nece[x], depth + 1);
  }
  if (func[u] == "IN") {
    if(v == depth) ans[u] = cur[1] ^ 1;
    else ans[u] = cur[1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> func[i];
    if (func[i] == "AND" || func[i] == "XOR" || func[i] == "OR") cin >> x >> y,  G[i].push_back(x),  G[i].push_back(y);
    else if (func[i] == "IN") cin >> x, cur[i] = x;
    else cin >> x, G[i].push_back(x);
  }
  dfs1(1);
  dfs2(1);
  dfs3(1, 0, 0);
  for (int i = 1; i <= n; i++) {
    if (func[i] == "IN") cout << ans[i];
  }
  cout << endl;
  return 0;
}

