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
const int M = 1e6 + 10;

int n, m;
int f[M];
int g[M], h[M];
vector<int> val[M];

int main() {
  int flag = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", f + i);
    if (f[i] == i) {
      m++;
      h[m] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[f[i]] != f[i]) {
      flag = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int key = lower_bound(h + 1, h + 1 + m, f[i]) - h;
    val[key].pb(i);
  }
  if (flag == 0) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", m);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < val[i].size(); j++) {
      g[val[i][j]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", g[i]);
  }
  printf("\n");
  for (int i = 1; i <= m; i++) {
    printf("%d ", h[i]);
  }
  printf("\n");
  return 0;
}

