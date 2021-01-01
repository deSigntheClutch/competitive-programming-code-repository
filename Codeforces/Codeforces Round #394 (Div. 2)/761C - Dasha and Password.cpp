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

const int N = 56;

int n, m;
char s[N][N];
int t[N][N];

int cal(int type, int r) {
  int res = 11111;
  for(int i = 0; i < m; i++) {
    if(t[r][i] == type) {
      res = min(res, min(i, m - i));
    }
  }
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] >= '0' && s[i][j] <= '9') {
        t[i][j] = 1;
      } else if (s[i][j] >= 'a' && s[i][j] <= 'z') {
        t[i][j] = 2;
      } else {
        t[i][j] = 0;
      }
    }
  }
  int ans = 11111;
  for (int t1 = 0; t1 < n; t1++) {
    for (int t2 = 0; t2 < n; t2++) {
      for (int t3 = 0; t3 < n; t3++) {
        if (t1 == t2 || t2 == t3 || t1 == t3) continue;
        ans = min(ans, cal(0, t1) + cal(1, t2) + cal(2, t3));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}

