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
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n++;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool flag = true;
  int key = -1;
  for (int i = 1; i < n - 1; i++) {
    if (a[i] >= 2 && a[i + 1] >= 2) {
      key = i;
      flag = false;
      break;
    }
  }
  if (flag) cout << "perfect" << endl;
  else {
    cout << "ambiguous" << endl;
    cout << 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
      if (i == key) {
        for (int j = 0; j < a[i]; j++) {
          cout << " " << cnt;
        }
        cnt += a[i];
        cout << " " << cnt - 1;
        for (int j = 1; j < a[i + 1]; j++) {
          cout << " " << cnt;
        }
        cnt += a[i + 1];
        i++;
      } else {
        for (int j = 0; j < a[i]; j++) {
          cout << " " << cnt;
        }
        cnt += a[i];
      }
    }
    cout << endl;
    cout << 0;
    cnt = 1;
    for (int i = 1; i < n; i++) {
      if (i == key) {
        for (int j = 0; j < a[i]; j++) {
          cout << " " << cnt;
        }
        cnt += a[i];
        cout << " " << cnt - 1;
        for (int j = 1; j < a[i + 1]; j++) {
          cout << " " << cnt - 1;
        }
        cnt += a[i + 1];
        i++;
      } else {
        for (int j = 0; j < a[i]; j++) {
          cout << " " << cnt;
        }
        cnt += a[i];
      }
    }
    cout << endl;
  }
  return 0;
}

