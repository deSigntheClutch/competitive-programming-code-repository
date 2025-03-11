#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main() {
      ll x[3], y[3];
      int T;
      cin >> T;
      while (T--) {
            for (int i = 0; i < 3; i++) {
                  cin >> x[i] >> y[i];
            }

            if (x[1] > x[2] || (x[1] == x[2] && y[1] > y[2])) {
                  swap(x[1], x[2]);
                  swap(y[1], y[2]);
            }

            if (x[0] < x[1]) {
                  if ((y[1] - y[0]) * (y[2] - y[0]) < 0) {
                        cout << min(abs(x[1] - x[0]), abs(x[2] - x[0])) + 1 << endl;
                  } else {
                        cout << min(abs(x[1] - x[0]), abs(x[2] - x[0])) + min(abs(y[1] - y[0]), abs(y[2] - y[0])) + 1 << endl;
                  }
            } else if (x[2] < x[0]) {
                  if ((y[1] - y[0]) * (y[2] - y[0]) < 0) {
                        cout << min(abs(x[1] - x[0]), abs(x[2] - x[0])) + 1 << endl;
                  } else {
                        cout << min(abs(x[1] - x[0]), abs(x[2] - x[0])) + min(abs(y[1] - y[0]), abs(y[2] - y[0])) + 1 << endl;
                  }
            } else {
                  if ((y[1] - y[0]) * (y[2] - y[0]) < 0) {
                        cout << 1 << endl;
                  } else {
                        cout << min(abs(y[1] - y[0]), abs(y[2] - y[0])) + 1 << endl;
                  }
            }
      }
}