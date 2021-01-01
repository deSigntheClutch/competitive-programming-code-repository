#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int N = 1e5 + 10;
typedef long long ll;

int vis[N];
int n, k;
ll p[N], q[N];
pair<pair<ll, ll>, int> a[N];
ll sa, sb;

bool cmp(pair<pair<ll, ll>, int> u, pair<pair<ll, ll>, int> v) {
  if (u.fi.fi != v.fi.fi) return u.fi.fi > v.fi.fi;
  else return u.fi.se > v.fi.se;
}

bool solve(vector<int> nu) {
  memset(vis, 0, sizeof vis);
  ll c1 = 0, c2 = 0;
  for (int x : nu) {
    vis[x] = 1;
    c1 += p[x];
    c2 += q[x];
  }
  if(nu.size() == k) {
    if (2 * (c1) > sa && 2 * (c2) > sb) {
        for (int x : nu) {
          printf("%d ", x);
        }
        puts("");
        return true;
    }
    else return false;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    else {
      if (2 * (c1 + p[i]) > sa && 2 * (c2 + q[i]) > sb) {
        printf("%d ", i);
        for (int x : nu) {
          printf("%d ", x);
        }
        puts("");
        return true;
      }
    }
  }
  return false;
}


int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i].fi.fi);
    p[i] = a[i].fi.fi;
    sa += a[i].fi.fi;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i].fi.se);
    q[i] = a[i].fi.se;
    sb += a[i].fi.se;
    a[i].se = i;
  }
  k = n / 2 + 1;
  ll c1 = 0, c2 = 0;
  sort(a + 1, a + 1 + n, cmp);
  printf("%d\n", k);
  vector<int> ans1, ans2;
  for (int i = 1; i <= n; i += 2) {
    ans1.push_back(a[i].se);
  }
  bool flag = solve(ans1);
  if (flag) return 0;
  for (int i = 2; i <= n; i += 2) {
    ans2.push_back(a[i].se);
  }
  solve(ans2);
  return 0;
}

/*


5
8 7 4 8 3
4 2 5 3 7

*/
