#include <bits/stdc++.h>
using namespace std;

int n, m, k;

string s;

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> m >> k;
            cin >> s;

            int ans = 0, accu = 0;
            for (int i = 0; i < n; i++) {
                  if (s[i] == '1') {
                        accu = 0;
                  } else {
                        accu += 1;
                        if (accu == m) {
                              ans += 1;
                              for (int j = i; j < i + k - 1; j++) {
                                    if (j == n) {
                                          break;
                                    } else {
                                          s[j] = '1';
                                    }
                              }
                              i = i + k - 1;
                              accu = 0;
                        }

                  }
            }
            cout << ans << endl;
      }
      return 0;
}
