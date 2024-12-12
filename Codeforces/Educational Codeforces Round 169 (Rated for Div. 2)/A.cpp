#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;

int T;
int n;
int a[100];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (n >= 3) {
      cout << "NO" << endl;
    } else {
      if (abs(a[1] - a[2]) > 1) cout << "YES" << endl;
      else cout << "NO" << endl;
    }
  }
  return 0;
}
