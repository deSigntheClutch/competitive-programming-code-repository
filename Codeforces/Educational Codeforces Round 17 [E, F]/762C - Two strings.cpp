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
const int INF = 1e9 + 10;

char a[N], b[N];
int pos[N], posrev[N], n, m;
bool gao = false;

int main() {
  scanf("%s%s", a + 1, b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  if (b[1] == 'd' && b[2] == 'm') gao = true;
  int pt = 1;
  for (int i = 1; i <= m; i++) {
    while (pt <= n && b[i] != a[pt]) pt++;
    pos[i] = pt;
    pt++;
  }
  pt = n;
  for (int i = m; i >= 1; i--) {
    while (pt >= 1 && b[i] != a[pt]) pt--;
    posrev[i] = pt;
    pt--;
  }
  int ans = 0, l = -1, r = -1;
  for (int i = 0; i <= m; i++) {
    if (pos[i] > n) break;
    int l_ = i + 1, r_ = m + 1, md;
    for (int cs = 0; cs < 20; cs++) {
      md = (l_ + r_) >> 1;
      if (pos[i] >= posrev[md]) l_ = md + 1;
      else r_ = md;
    }
    if (md > m) {
      if(ans >= i) continue;
      ans = i;
      l = i, r = m + 1;
      continue;
    }
    if (ans < (m - md + 1 + i)) {
      ans = m - md + i + 1;
      l = i, r = md;
    }
  }
  if (ans >= m) {
    printf("%s\n", b + 1);
    return 0;
  }
  if (ans == 0) {
    printf("-\n");
    return 0;
  }
  for (int i = 1; i <= l; i++) {
    printf("%c", b[i]);
  }
  for (int i = r; i <= m; i++) {
    printf("%c", b[i]);
  }
  printf("\n");
  return 0;
}

/*


aa
aaab

*/
