#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
int a[N];

int main() {
      int T; cin >> T; while (T--) {
            cin >> n;
            bool flag = true;
            for (int i = 0; i < n; i++) {
                  cin >> a[i];

                  int len = (a[i] - 1) / 2;

                  if (i + len >= n - 1 && i - len <= 0) {
                        continue;
                  } else {
                        flag = false;
                  }
            }
            cout << ((flag) ? "yes" : "no") << endl;
      }
      return 0;
}
