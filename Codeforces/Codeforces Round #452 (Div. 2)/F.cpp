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

const int N = 2e5 + 10;

int n, m;
string str;
set<int> s[150];
int fwt[N];

void add(int u, int x) {
  while (u <= n) {
    fwt[u] += x;
    u += u & -u;
  }
}

int sum(int u) {
  int res = 0;
  while (u) {
    res += fwt[u];
    u -= u & -u;
  }
  return res;
}

bool check(int u, int x) {
  if (u == 0) return false;
  if (u - sum(u) >= x) return true;
  return false;
}

int real(int u) {
  int l = 0, r = n, md;
  while (l < r) {
    md = (l + r) >> 1;
    if (!check(md, u)) l = md + 1;
    else r = md;
  }
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> str;
  for (int i = 0; i < str.length(); i++) {
    s[str[i]].insert(i + 1);
  }
  while (m--) {
    string op;
    int l, r;
    cin >> l >> r >> op;
    l = real(l);
    r = real(r);
    auto it = s[op[0]].lower_bound(l);
    while (it != s[op[0]].end() && *it <= r) {
      add(*it, 1);
      it = s[op[0]].erase(it);
    }
  }
  vector<pair<int, char>> ans;
  for (int i = 0; i < 150; i++) {
    for (int x : s[i]) {
      ans.pb(mp(x, (char)i));
    }
  }
  sort(ans.begin(), ans.end());
  for (auto x : ans) {
    cout << x.se;
  }
  cout << endl;
  return 0;
}
