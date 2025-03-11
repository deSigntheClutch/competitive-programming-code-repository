#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], b[N];

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
            }

            for (int i = 1; i <= n; i++) {
                  cin >> b[i];
            }

            int idx = 0, cnt = 0;

            for (int i = 1; i <= n; i++) {
                  if (a[i] < b[i]) {
                        idx = i;
                        cnt += 1;
                  }
            }

            if (cnt == 0) {
                  cout << "yes" << endl;
                  continue;
            }

            if (cnt > 1) {
                  cout << "no" << endl;
                  continue;
            }

            int diff = b[idx] - a[idx];
            bool flag = true;
            for (int i = 1; i <= n; i++) {
                  if (idx != i) {
                        if (a[i] - diff < b[i]) {
                              flag = false;
                        }
                  }
            }

            cout << (flag? "yes" :"no" ) << endl;
      }

      return 0;
}