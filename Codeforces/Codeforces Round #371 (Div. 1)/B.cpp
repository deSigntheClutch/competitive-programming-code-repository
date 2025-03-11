#include <bits/stdc++.h>

using namespace std;


int cnt;
int n;

int ask(int x1, int y1, int x2, int y2) {
      if (x2 > n && x1 == 1 && y1 == 1 && y2 == n) {
            return 1;
      }

      if (x1 <= 0 && y1 == 1 && x2 == n && y2 == n) {
            return 1;
      }

      if (x1 == 1 && y1 == 1 && x2 == n && y2 > n) {
            return 1;
      }

      if (x1 == 1 && y1 <= 0 && x2 == n && y2 == n) {
            return 1;
      }

      assert(cnt <= 200);

      cnt += 1;
      cout << "? " << x1  << " " << y1 << " " << x2 << " " << y2 << endl;
      fflush(stdout);

      int res;
      cin >> res;
      return res;
}


int main() {
      cin >> n;

      cnt = 0;
      // x1

      int X0, Y0, X1, Y1;

      int l = 1, r = n + 1, md;
      for (int i = 0; i < 18; i++) {
            md = (l + r >> 1);
            if (ask(1, 1, md, n) == 0) {
                  l = md + 1;
            } else {
                  r = md;
            }
      }

      // l
      X1 = l;

      // x0
      l = 0, r = n, md;
      for (int i = 0; i < 18; i++) {
            md = (l + r >> 1);
            if (ask(md, 1, n, n) == 1) {
                  l = md + 1;
            } else {
                  r = md;
            }
      }

      // l - 1;
      X0 = l - 1;

      // y1
      l = 1, r = n + 1, md;
      for (int i = 0; i < 18; i++) {
            md = (l + r >> 1);
            if (ask(1, 1, n, md) == 0) {
                  l = md + 1;
            } else {
                  r = md;
            }
      }

      // l
      Y0 = l;

      // y0
      l = 0, r = n, md;
      for (int i = 0; i < 18; i++) {
            md = (l + r >> 1);
            if (ask(1, md, n, n) == 1) {
                  l = md + 1;
            } else {
                  r = md;
            }
      }

      // l - 1
      Y1 = l - 1;

      cout << "! " << X0

      return 0;
}