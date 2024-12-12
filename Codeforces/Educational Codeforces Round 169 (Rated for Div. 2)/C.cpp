#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 4;

int T, n, k;
int a[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    long long sum = 0;
    for (int i = n; i > 1; i -= 2) {
      sum += (a[i] - a[i - 1]);
    }
    cout << max(0ll, sum - k) + (n & 1 ? a[1] : 0) << endl;
  }
  return 0;
}
