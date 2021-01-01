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
int n;
ll a[123456];

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%I64d", a+i);
  }
  sort(a+1,a+1+n);
  for(int i = 1; i <= n - 2; i++) {
    if(a[i] + a[i + 1] > a[i + 2]) {
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}


