#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 0; i < n; i++) {
                  cin >> a[i];
            }
            bool flag = false;
            for (int i = 0; i < n - 1; i++) {
                  int u = a[i];
                  int v = a[i + 1];
                  if (u > v) swap(u, v);

                  if (u + u > v) {
                        flag = true;
                  }
            }

            cout << ((flag) ? "YES" : "NO") << endl;
      }
      return 0;
}