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

ll n, k;
vector<ll> divisor;

int main() {
  cin >> n >> k;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      divisor.pb(i);
      if(i * i != n) divisor.pb(n / i);
    }
  }
  sort(divisor.begin(), divisor.end());
  if(divisor.size() < k) {
    cout << -1 << endl;
  } else {
    cout << divisor[k - 1] << endl;
  }
  return 0;
}

