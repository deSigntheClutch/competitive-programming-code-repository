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

int n, l;
ll s, t, f, a[N];
pair<ll, ll> p[N];

int main() {
  scanf("%I64d %I64d %I64d", &s, &t, &f);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
  }
  if(n == 0 || a[1] > s) {
    printf("%I64d\n", s);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    int pt = i;
    while (a[pt] == a[i] && pt <= n) pt++;
    p[++l] = mp(a[i], pt - i);
    i = pt - 1;
  }
  p[l + 1].fi = 1e15 + 10;
  ll ans = max(s, a[1] - 1) - (a[1] - 1);
  ll ti = a[1] - 1;
  ll sum = 0;
  ll lasttime = s;
  for (int i = 1; i <= l; i++) {
    sum += p[i].se;
    ll dotime = min(lasttime + p[i].se * f, p[i + 1].fi - 1);
    ll finishtime = lasttime + p[i].se * f;
    if (finishtime - dotime < ans && finishtime + f <= t) {
      ans = finishtime - dotime;
      ti = dotime;
    }
    lasttime = finishtime;
  }
  printf("%I64d\n", ti);
  return 0;
}

