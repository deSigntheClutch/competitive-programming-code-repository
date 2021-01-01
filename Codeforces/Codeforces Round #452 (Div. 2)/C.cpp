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
int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n % 4 == 0) {
    cout << 0 << endl;
    cout << n / 2;
    for (int i = 1; i <= n / 2; i += 2) {
      cout << " " << i << " " << n - i + 1;
    }
    cout << endl;
  } else if (n % 4 == 2) {
    cout << 1 << endl;
    cout << n / 2;
    for (int i = 1; i < n / 2; i += 2) {
      cout << " " << i << " " << n - i + 1;
    }
    cout << " " << n / 2 << endl;
  } else if ((n + 1) % 4 == 0) {
    int cnt = 0;
    cout<<0<<endl;
    cout << n / 2;
    for (int i = n; i > 1; i -= 2) {
      cnt++;
      if (cnt & 1)cout << " " << i;
      else cout << " " << i - 1;
    }
    cout << endl;
  } else {
    cout<<1<<endl;
    int cnt = 0;
    cout << n / 2;
    for (int i = n; i > 1; i -= 2) {
      cnt++;
      if (cnt & 1)cout << " " << i;
      else cout << " " << i - 1;
    }
    cout<<endl;
  }
  return 0;
}
