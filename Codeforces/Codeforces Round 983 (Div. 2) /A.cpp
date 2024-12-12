#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 4;
const int INF = 1e9 + 10;

int T, n;
int a[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n * 2; i++) {
      cin >> a[i];
      sum += a[i];
    }

    cout << sum % 2 << " " << ((sum <= n) ? sum : 2 * n - sum) << endl;
  }
  return 0;
}
