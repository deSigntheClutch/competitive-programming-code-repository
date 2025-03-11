#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;
            if (n == 6) {
                  cout << "1 1 2 3 1 2" << endl;
                  continue;
            } else if (n == 7) {
                  cout << "1 1 2 7 6 1 2" << endl;
                  continue;
            } else if (n == 8) {
                  cout << "1 1 2 8 7 6 1 2" << endl;
                  continue;
            } else if (n == 9) {
                  cout << "7 3 3 7 5 3 7 7 3" << endl;
                  continue;
            }

            int m = n / 3;

            vector<int> ans;

            for (int i = 1; i <= m; i++) {
                  ans.push_back(i);
            }

            for (int i = 1; i <= (n - 2 * m); i++) {
                  ans.push_back(n + 1 - i);
            }

            for (int i = 1; i <= m; i++) {
                  ans.push_back(i);
            }

            for (int v : ans) {
                  cout << v << " ";
            }
            cout << endl;
      }
      return 0;
}