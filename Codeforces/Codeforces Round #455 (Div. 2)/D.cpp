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

const int N = 1e6 + 10;

string s;
set<int> S;
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.length();

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int pt = i;
    while (pt < n && s[pt] == s[i]) pt++;
    S.insert(i);
    S.insert(pt - 1);
    i = pt - 1;
  }

  while (true) {
    set<int> V;
    for (int x : S) {
      auto it = S.lower_bound(x);
      auto itn = next(it);
      if (itn == S.end()) {
        V.insert(x);
        continue;
      }

      if (s[*it] == s[*itn]) {
        if (it == S.begin()) V.insert(x);
      } else {
        // left
        auto last = --V.end();
        if (*last == x) {
          V.insert(x);
          V.erase(x);
        } else {
          V.insert(x - 1);
        }
        cout << "x: " << x << endl;
        cout << "left: " << endl;
        for (int x : V) {
          cout << x << " ";
        }
        cout << endl;
        // right
        auto itx = next(itn);
        if (itx == S.end() || s[*itx] != s[*itn]) {
          continue;
        } else {
          V.insert(*itn + 1);
          V.erase(*itn);
        }
        cout << "right: " << endl;
        for (int x : V) {
          cout << x << " ";
        }
        cout << endl;
      }
    }
    for (int x : S) {
      cout << x << " ";
    }
    cout << endl;
    if ((int)S.size() == (int)V.size()) break;
    ans++;
    S = V;
  }

  cout << ans << endl;
  return 0;
}

/*

aaabaaabbbaaa

*/
