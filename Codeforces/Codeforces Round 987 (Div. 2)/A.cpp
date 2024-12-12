#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[55];

int main() {
  int T, n;
  cin >> T;
  for (int cs = 0; cs < T; cs++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
      int cur = 0;
      for (int j = 0; j < i; j++) {
        if (a[j] != a[i]) {
          cur += 1;
        }
      }
      for (int j = i + 1; j < n; j++) {
        if (a[j] != a[i]) {
          cur += 1;
        }
      }
      ans = min(ans, cur);
    }
    cout << ans << endl;
  }
  return 0;
}
