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

string s;
int b[N], a[N], n;

bool check(int x) {
  memcpy(a, b, sizeof a);
  queue<int> Q;
  int res = 1;
  for (int i = 0; i + x - 1 < n; i++) {
    a[i] ^= ((int)Q.size() & 1);
    if (a[i]) Q.push(i + x - 1);
    if (Q.front() == i) Q.pop();
  }
  for (int i = n - x + 1; i < n; i++) {
    a[i] ^= ((int)Q.size() & 1);
    if (a[i]) {
      res = n - i;
      break;
    }
    if (Q.front() == i) Q.pop();
  }
  if (res == -1) return true;
  return res <= n - x;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    b[i] = (s[i] == '1');
  }
  int l = 1, r = n, md;
  for (int i = 0; i < 22; i++) {
    md = (l + r) >> 1;
    if (check(md)) l = md + 1;
    else r = md;
  }
  cout << md - 1 << endl;
  return 0;
}

