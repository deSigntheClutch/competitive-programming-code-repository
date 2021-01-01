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
const int INF = 1e9 + 7;
const int N = 1e5 + 10;

vector<int> factor[N];
vector<int> mul[N];
int root[N];
int cnt = 1;
int q;

struct Node {
  int to[2];
  int val;
} t[N * 100];


void init() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      mul[i].pb(j);
      factor[j].pb(i);
    }
  }
  for (int i = 1; i < N; i++) {
    root[i] = i;
    t[i].to[0] = -1;
    t[i].to[1] = -1;
    t[i].val = INF;
    cnt++;
  }
}

void add(int rt, int x) {
  int cur = rt;
  t[cur].val = min(t[cur].val, x);
  for (int i = 0; i < 18; i++) {
    int c = x >> (18 - i - 1) & 1;
    if (t[cur].to[c] == -1) {
      t[cur].to[c] = cnt++;
      cur = cnt - 1;
      t[cnt - 1].val = INF;
      t[cnt - 1].to[0] = -1;
      t[cnt - 1].to[1] = -1;
    } else {
      cur = t[cur].to[c];
    }
    t[cur].val = min(t[cur].val, x);
   // cout << cur << " " << x << " " << t[cur].val <<endl;
  }
}

int get(int rt, int bound, int prefer) {
  int cur = rt;
  for (int i = 0; i < 18; i++) {
    int pref = prefer >> (18 - i - 1) & 1;
    //cout << i << " " << pref << " " << t[t[cur].to[1]].val << " " << t[t[cur].to[0]].val <<endl;
    if (pref == 0) { // move by 1
    if (t[cur].to[1] != -1 && t[t[cur].to[1]].val <= bound) cur = t[cur].to[1];
      else if (t[cur].to[0] == -1 || t[t[cur].to[0]].val > bound) return -1;
      else cur = t[cur].to[0];
    } else {
      if (t[cur].to[0] != -1 && t[t[cur].to[0]].val <= bound) cur = t[cur].to[0];
      else if (t[cur].to[1] == -1 || t[t[cur].to[1]].val > bound) return -1;
      else cur = t[cur].to[1];
    }
  }
  return t[cur].val;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> q;
  init();
  while (q--) {
    int t, x, k, s;
    cin >> t;
    if (t == 1) {
      cin >> x;
      for (int v : factor[x]) {
        int rt = root[v];
        //cout << v << " + " << x << endl;
        add(rt, x);
      }
    } else {
      cin >> x >> k >> s;
      if (s - x <= 0) cout << -1 << endl;
      else if (x % k != 0) cout << -1 << endl;
      else {
        int rt = root[k];
       // cout << rt << endl;
        cout << get(rt, s - x, x) << endl;
      }
    }
  }
  return 0;
}

/*

10
1 9
1 25

*/
