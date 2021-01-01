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


int main() {
  int a, b;
  cin >> a >> b;
  if (a + b == 0) cout << "NO" << endl;
  else {
    if (abs(a - b) <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

