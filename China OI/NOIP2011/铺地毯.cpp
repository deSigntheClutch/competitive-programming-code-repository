#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;


int n;
int a[N], b[N], w[N], d[N];
int x, y;

bool isIn(int idx) {
      int x0 = a[idx], y0 = b[idx];
      int x1 = a[idx] + w[idx], y1 = b[idx] + d[idx];

      return x0 <= x && x1 >= x && y0 <= y && y1 >= y;
}

int main() {
      cin >> n;

      for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i] >> w[i] >> d[i];
      }

      cin >> x >> y;

      int ans = -1;
      for (int i = n - 1; i >= 0; i--) {
            if (isIn(i)) {
                  ans = i + 1;
                  break;
            }
      }

      cout << ans << endl;
      return 0;
}