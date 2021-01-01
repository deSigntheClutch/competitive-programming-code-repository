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

char a[123456], b[123456];
int vis[2][1234];

int main() {
  scanf("%s", a);
  scanf("%s", b);
  int l1 = strlen(a), l2 = strlen(b);
  if(l1 != l2) {
    printf("%d\n", max(l1, l2));
    return 0;
  }
  bool flag = true;
  for (int i = 0; i < l1; i++) {
    if(a[i] != b[i]) flag = false;
  }
  if(flag) printf("-1\n");
  else printf("%d\n", l1);
  return 0;
}

