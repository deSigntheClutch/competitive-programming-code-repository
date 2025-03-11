#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, k;
int a[N];

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> k;
            bool flag = true;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  if (a[i] == 1) flag = false;
            }

            if (flag) {
                  cout << "NO" << endl;
            } else {
                 cout << "YES" << endl;
            }
      }

      return 0;
}