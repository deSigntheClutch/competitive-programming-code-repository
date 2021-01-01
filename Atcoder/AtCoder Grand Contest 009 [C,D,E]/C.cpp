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
const ll INF = 9e18 + 10;
const ll MOD = 1e9 + 7;

int n;
ll a, b, s[N], fa[N], fb[N], suma[N], sumb[N], posa[N], posb[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  posa[1] = posb[1] = 1;
  for (int i = 2; i <= n; i++) {
    ll dif = s[i] - s[i - 1];
    if (dif < a) {
      posa[i] = i;
    } else {
      posa[i] = posa[i - 1];
    }
    if (dif < b) {
      posb[i] = i;
    } else {
      posb[i] = posb[i - 1];
    }
  }
  fa[0] = fb[0] = suma[0] = sumb[0] = 0;
  fa[1] = fb[1] = 1;
  suma[1] = 1, sumb[1] = 1;
  for (int i = 2; i <= n; i++) {
    int pos = posa[i];
    fa[i] = (sumb[i - 1] - sumb[pos - 2] + MOD) % MOD;
    pos = posb[i];
    fb[i] = (suma[i - 1] - suma[pos - 2] + MOD) % MOD;
    suma[i] = (suma[i - 1] + fa[i]) % MOD;
    sumb[i] = (sumb[i - 1] + fb[i]) % MOD;
    printf("%lld %lld\n", fa[i], fb[i]);
  }
  printf("%lld\n", (fa[n] + fb[n]) % MOD);
  return 0;
}
