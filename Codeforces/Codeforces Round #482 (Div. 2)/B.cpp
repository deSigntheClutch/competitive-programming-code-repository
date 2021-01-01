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

string s[3];
int c[1234], n;

int cal(string s) {
  memset(c, 0, sizeof c);
  int len = s.length();
  int res = 0;
  for (int i = 0; i < len; i++) {
    c[s[i]]++;
    res = max(res, c[s[i]]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<pair<int, int>> V;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
    int len = s[i].length();
    int val = cal(s[i]);
    if(val + n > len){
      if(val == len && n == 1) V.push_back(mp(len - 1, i));
      else V.push_back(mp(len, i));
    } else {
      V.push_back(mp(val + n, i));
    }
  }
  sort(V.begin(), V.end());
  if (V[2].fi == V[1].fi) {
    cout << "Draw" << endl;
    return 0;
  }
  if (V[2].se == 0) {
    cout << "Kuro" << endl;
    return 0;
  }
  if (V[2].se == 1) {
    cout << "Shiro" << endl;
    return 0;
  }
  if (V[2].se == 2) {
    cout << "Katie" << endl;
    return 0;
  }
  return 0;
}
