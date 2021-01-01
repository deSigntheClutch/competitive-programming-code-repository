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

struct edge {
  int u, v;
} e[N];

int pa[N];
string a, b;
int n, len;

int find(int x) {
  if (pa[x] != x) return pa[x] = find(pa[x]);
  return pa[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      e[len].u = a[i] - 'a';
      e[len].v = b[i] - 'a';
      len++;
    }
  }
  for (int i = 0; i < 26; i++) {
    pa[i] = i;
  }
  vector<pair<char,char>> vec;
  for(int i = 0; i < len; i++) {
    if(find(e[i].u) != find(e[i].v)) {
      int x = find(e[i].u), y = find(e[i].v);
      pa[x] = y;
      vec.pb(mp(e[i].u,e[i].v));
    }
  }
  cout << (int)vec.size() << endl;
  for(auto x : vec) {
    cout << (char)(x.fi+'a') << " " << (char)(x.se+'a') << endl;
  }
  return 0;
}

