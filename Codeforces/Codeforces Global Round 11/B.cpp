#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
 
int n, k;
string s;
 
int get_points() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (s[i] == s[i - 1] && s[i - 1] == 'W') res += 2;
            else if (s[i] == 'W') res += 1;
        }
        else {
            if (s[i] == 'W') res += 1;
        }
    }
    return res;
}
 
int main() {
      ios::sync_with_stdio(false);
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> k >> s;

            int l = 0, r = n - 1;
            while (l < n & s[l] == 'L') l++;
            while (r >= 0 & s[r] == 'L') r--;

            if (l == n) {
                  if (k <= 1) {
                        cout << k << endl;
                  } else {
                        cout << 2 * (k - 1) + 1 << endl;
                  }
                  continue;
            }

            int ans = get_points();
            priority_queue<int, vector<int>, greater<>> Q;
            for (int i = l; i <= r; i++) {
                  if (s[i] == 'W') continue;
                  int pt = i;
                  while (pt <= r & s[pt] == 'L') pt += 1;
                  Q.push(pt - i);
                  i = pt - 1;
            }

            int inc = 0;
            while (!Q.empty()) {
                    int x = Q.top();
                    if (k >= x) {
                          k -= x;
                          inc += 2 * x + 1;
                    } else {
                          inc += 2 * k;
                          k = 0;
                          break;
                    }
                    Q.pop();
            }

            while (!Q.empty()) Q.pop();

            if (k) {
                  Q.push(l);
                  Q.push(n - 1 - r);

                  while (!Q.empty()) {
                        int x = Q.top();

                        if (k >= x) {
                              k -= x;
                              inc += 2 * x;
                        } else {
                              inc += 2 * k;
                              k = 0;
                              break;
                        }
                        Q.pop();
                  }
            }

            cout << inc + ans << endl;
      }
    return 0;
}
