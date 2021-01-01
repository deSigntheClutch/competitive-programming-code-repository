#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug0(x) printf("! %d\n", x);
#define debug1(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define nono(x, ite) for(__typeof((x).begin()) (ite)=(x).begin();(ite)!=(x).end();(ite++))

typedef long long ll;

const int N = 2e5 + 10;

int n, lv;
ll a[N], ans[N], gar[N];
bool vis[N];
vector<int> pos;
ll s[2][N];

void add(int id, int u, ll v) {
  while (u <= lv) {
    s[id][u] += v;
    u += u & -u;
  }
}

ll get(int id, ll u) {
  ll res = 0;
  while (u) {
    res += s[id][u];
    u -= u & -u;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    gar[lv++] = a[i];
  }
  gar[lv++] = 0;
  ll mx = 0;
  pos.pb(0);
  for (int i = 1; i <= n; i++) {
    if (mx < a[i]) mx = a[i], pos.pb(i);
  }
  for (int i = 0; i < pos.size(); i++) {
    vis[pos[i]] = 1;
  }
  sort(gar, gar + lv);
  lv = unique(gar, gar + lv) - gar;
  for (int i = 0; i <= n; i++) {
    a[i] = lower_bound(gar, gar + lv, a[i]) - gar + 1;
  }
  ll tsum = 0;
  int len = pos.size() - 1;
  for (int i = n; i >= 1; i--) {
    add(0, a[i], 1);
    add(1, a[i], gar[a[i] - 1]);
    if (vis[i]) {
      ans[i] = (get(1, lv) - get(1, a[pos[len - 1]])) - tsum - (get(0, lv) - get(0, a[pos[len - 1]])) * gar[a[pos[len - 1]] - 1];
      tsum += ans[i];
      len--;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}

