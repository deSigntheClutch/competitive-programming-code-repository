#include <bits/stdc++.h>


using namespace std;

const int N = 1e3 + 1;

long double a[N], b[N];
int n;

int main() {
      int T;
      scanf("%d", &T);
      for (int cs = 1; cs <= T; cs++) {
            printf("Case #%d: ", cs);
            scanf("%d", &n);

            for (int i = 1; i <= n; i++) {
                  scanf("%lf:%lf", &a[i], &b[i]);
            }


      }
      return 0;
}