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

const int N = 100 + 10; // RE - 100

int n;
ll a[N];

int main() {

  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a+i);
  }
  ll val = *max_element(a+1,a+1+n);
  ll ans = 0;
  for(int i = 1; i<=n;i++){
    ans += (val - a[i]);
  }
  printf("%I64d\n", ans);
  return 0;
}

