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

const int N = 1e5 + 10;

int n;
ll l, r;
ll a[N], b[N], c[N];
pair<pair<ll, ll>, ll> p[N];

int main() {
  scanf("%d%I64d%I64d", &n, &l, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", c + i);
  }
  for (int i = 1; i <= n; i++) {
    p[i] = mp(mp(c[i], a[i]), i);
  }
  sort(p + 1, p + 1 + n);
  ll delta = l - p[1].fi.se;
  b[p[1].se] = l;
  bool flag = true;
  for (int i = 2; i <= n; i++) {
    delta++;
    ll res = p[i].fi.se + delta;
    if (res < l) {
      res = l;
      delta = l - p[i].fi.se;
    }
    b[p[i].se] = res;
  }
  for (int i = 1; i <= n; i++) {
    if(b[i] < l || b[i] > r) {
      flag = false;
    }
  }
  if(!flag) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    printf("%I64d ", b[i]);
  }
  printf("\n");

  return 0;
}

