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

ll k, a, b;

int main() {
  cin >> k >> a >> b;
  if (a < b) swap(a, b);
  ll win_a = a / k;
  if (a % k == 0) {
    cout << win_a + (b / k) << endl;
  } else {
    if (b < k) {
      cout << -1 << endl;
    } else {
      cout << win_a + (b / k) << endl;
    }
  }
  return 0;
}
