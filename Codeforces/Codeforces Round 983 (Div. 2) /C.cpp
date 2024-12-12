#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const int INF = 1e9 + 10;

int T, n;
int a[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);

    int ans = n;
    for (int i = 1; i < n; i++) {
      int maxVal = a[i] + a[i + 1];
      int idx = lower_bound(a + 1, a + 1 + n, maxVal) - a;
      ans = min(ans, i - 1 + n - idx + 1);
    }

    cout << ans << endl;
  }
  return 0;
}
