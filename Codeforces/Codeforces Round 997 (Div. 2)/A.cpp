#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m;

int main() {
      int T;
      cin >> T;
      while (T--) {
            int x = 0, y = 0;
            cin >> n >> m;

            int minx = 1e9 + 1, miny = 1e9 + 1, maxy = 0, maxx = 0;
            for (int i = 1; i <= n; i++) {
                  int a, b;
                  cin >> a >> b;

                  x = x + a;
                  y = y + b;

                  minx = min(minx, x);
                  miny = min(miny, y);
                  maxx = max(maxx, x + m);
                  maxy = max(maxy, y + m);
            }
            //cout << minx << " " << maxx << " " << miny << " " << maxy << endl;
            cout << 2ll * (maxy - miny) + 2ll * (maxx - minx) << endl;
      }
      return 0;
}