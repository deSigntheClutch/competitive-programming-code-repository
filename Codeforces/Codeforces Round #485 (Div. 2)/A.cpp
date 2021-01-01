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
map<string, string> m;
map<string, string> v;
map<string, bool> vis;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  m["Power"] = "purple";
  m["Space"] = "blue";
  m["Soul"] = "orange";
  m["Mind"] = "yellow";
  m["Time"] = "green";
  m["Reality"] = "red";
  v["purple"] = "Power";
  v["blue"] = "Space";
  v["orange"] = "Soul";
  v["yellow"] = "Mind";
  v["green"] = "Time";
  v["red"] = "Reality";
  set<string> ss;
  ss.insert("Reality");
  ss.insert("Time");
  ss.insert("Mind");
  ss.insert("Soul");
  ss.insert("Space");
  ss.insert("Power");
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    ss.erase(v[s]);
  }
  cout << 6 - n << endl;
  for (string ik : ss) {
    cout << ik << endl;
  }
  return 0;
}

