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

ll a, b;

bool check(ll u) {
  if(a >= u) {
    return b >= 2 * u;
  }
  ll p = a, q = b;
  q -= (u - a) * 2;
  return (q >= u * 2);
}

int main() {
  cin >> a >> b;
  ll l = 0, r = 1e12 + 10, md;
  for (int i = 0; i < 66; i++) {
    md = (l + r) >> 1;
    if (check(md)) l = md + 1;
    else r = md;
  }
  cout << md - 1 << endl;
  return 0;
}

