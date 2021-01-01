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

set<int> l;
set<pair<int, int>> S;

int n;
int a[N];
int length[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  l.insert(0);
  l.insert(n + 1);
  for (int i = 1; i <= n; i++) {
    int pt = i;
    while (a[i] == a[pt] && pt <= n) pt++;
    S.insert(mp(-(pt - i), i));
    l.insert(i);
    length[i] = pt - i;
    i = pt - 1;
  }

  int ans = 0;
  while (!S.empty()) {
   /* for(auto x : S){
        cout <<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;*/
    ans++;
    auto nu = *S.begin();
    S.erase(S.begin());

    int lb = nu.second;
    auto se = l.lower_bound(lb);
    auto th = ++se;
    se--;
    auto fi = --se;
    se++;
    int f, s, t;

    if ((*th) == n + 1) {
      l.erase(se);
    } else if ((*fi) == 0) {
      l.erase(se);
    } else {
      pair<int, int> left, middle, right;
      f = *fi, t = *th;
      left = mp(-length[f], f);
      middle = nu;
      right = mp(-length[t], t);

      if (a[f] == a[t]) {
        auto pp = S.lower_bound(left);    //cout<<(*pp).first<<" "<<(*pp).second<<endl;
        S.erase(pp);
        auto ee = S.lower_bound(right);   // cout<<(*ee).first<<" "<<(*ee).second<<endl;
        S.erase(ee);


        S.insert(mp(-(length[f] + length[t]), f));
        length[f] += length[t];
        //cout<<*se<<*th<<endl;
        l.erase(se);
        l.erase(th);
      } else {
        l.erase(se);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
/*

7
4 4 2 2 2 4 4

*/
