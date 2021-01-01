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

ll a[N], b[N];
int n;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld %lld", a + i, b + i);
  }
  ll ans = 0;
  for (int i = n; i >= 1; i--) {
    a[i] = (a[i] + ans) % b[i];
    a[i] %= b[i];
    ans += (b[i] - a[i]) % b[i];
  }
  printf("%lld\n", ans);
  return 0;
}

