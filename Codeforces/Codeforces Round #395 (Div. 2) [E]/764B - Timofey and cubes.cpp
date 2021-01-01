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

const int N = 2e5 + 10;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  int cnt = 1;
  for (int i = 0; i < n / 2; i++) {
    if (cnt & 1) swap(a[i], a[n - 1 - i]);
    cnt++;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  puts("");
  return 0;
}

