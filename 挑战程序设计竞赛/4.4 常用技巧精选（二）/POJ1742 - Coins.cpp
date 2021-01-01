#include <cstdio>
using namespace std;

const int N = 111;
const int M = 111111;
const int S = 1111;

int n, m;
int a[N], c[N], dp[2][M], q[S], l, r;

int main() {
  while(~scanf("%d%d", &n, &m), n + m) {
    for(int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    for(int i = 0; i < n; i++) {
      scanf("%d", c + i);
    }
    for(int i = 0; i < n; i++) {
      memset(dp[i + 1 & 1], 0, sizeof dp[i + 1 & 1]);
      for(int j = 0; j < a[i]; j++) {
        int l = 0, r = 0;
        for(int k = 0; k * a[i] + j <= m; k++) {
          int cur = dp[i & 1][j + k * a[i]] + k * c[i];
          while(r - l >= 1 && q[r - 1] <= )
        }
      }
    }
  }
  return 0;
}
