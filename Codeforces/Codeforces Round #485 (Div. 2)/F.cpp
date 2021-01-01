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

const int N = (1 << 23) + 1;

int n, m;
int f[N];
int binary[26];
int a[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  f[0] = 1;
  for (int i = 0; i < m; i++) {
    if(i > 0){
      bool flag = false;
      for(int j = 0; j < 22; j++) {
        if(binary[j] == i && (a[i] >> j & 1)) flag = true;
      }
      if(!flag) f[i] = f[i - 1] + 1;
      else f[i] = f[i - 1];
    }
    int cnt = 0;
    while(a[i]) {
      if(a[i] & 1) binary[cnt++]++;
      else cnt++;
      a[i] >>= 1;
    }
  }
  for(int i = 0; i < m; i++){
    cout << i << ": " << f[i] << endl;
  }
  cout << f[m - 1] << endl;
  return 0;
}

