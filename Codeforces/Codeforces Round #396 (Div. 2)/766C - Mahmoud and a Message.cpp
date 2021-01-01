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

const int N = 1e3 + 10;
const int MOD = 1e9 + 7;

char str[N];
int n, l, vis[30], maxlen = 1;
int a[N], dp[N];

bool check(int len) {
  for (int i = 0; i < 26; i++) {
    if (vis[i]) {
      if (len > a[i]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  l = strlen(str + 1);
  for (int i = 0; i < 26; i++) {
    scanf("%d", a + i);
  }
  dp[0] = 1, dp[1] = 1;
  for (int i = 2; i <= l; i++) {
    memset(vis, 0, sizeof vis);
    for (int j = i - 1; j >= 0; j--) {
      int len = i - j;
      vis[str[j + 1] - 'a'] = 1;
      if (!check(len)) {
        break;
      }
      maxlen = max(maxlen, len);
      dp[i] = (dp[i] + dp[j]) % MOD;
    }
  }
  int mintime = 0;
  for(int i = 1; i <= l; i++) {
    memset(vis, 0, sizeof vis);
    int pt = i;
    vis[str[pt] - 'a'] = 1;
    while(pt <= l){
      if(!check(pt - i + 1)) {
        break;
      }
      pt++;
      vis[str[pt] - 'a'] = 1;
    }
    i = pt - 1;
    mintime++;
  }
  printf("%d\n%d\n%d\n", dp[l], maxlen, mintime);
  return 0;
}

