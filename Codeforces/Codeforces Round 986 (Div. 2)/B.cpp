#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, b, c;

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> b >> c;

            if (b == 0 && c == 0) {
                  if (n == 1) {
                        cout << 0 << endl;
                  } else if (n == 2) {
                        cout << 1 << endl;
                  } else {
                        cout << -1 << endl;
                  }
                  continue;
            }

            if (b == 0) {
                  if (n > c + 2) {
                        cout << -1 << endl;
                  } else {
                        if (c <= n - 1) {
                              cout << n - 1 << endl;
                        } else {
                              cout << n << endl;
                        }
                  }
                  continue;
            }

            ll k = (n - 1 - c) / b;
            ll ans = (n - 1 - c < 0) ? n : n - (k + 1);
            cout << ans << endl;
      }
      return 0;
}