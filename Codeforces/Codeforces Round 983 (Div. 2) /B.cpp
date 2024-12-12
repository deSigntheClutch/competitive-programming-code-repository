#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 4;
const int INF = 1e9 + 10;

int T, n, k;
int a[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> k;
    if (k == n && n > 2) {
      cout << -1 << endl;
      continue;
    }

    if (n == 1 && k == 1) {
      cout << 1 << endl << 1 << endl;
      continue;
    }

    if ((n - k) % 2 == 0) {
      if (k <= 2) {
        cout << -1 << endl;
      } else {
        cout << 5 << endl;
        cout << 1 << ' ' << 2 << " " << k << " " << k + 1 << " " << k + 2 << endl;
      }
    } else {
      if (k <= 1) {
        cout << -1 << endl;
      } else {
        cout << 3 << endl;
        cout << 1 << ' ' << k << " " << k + 1 << endl;
      }
    }
  }
  return 0;
}
