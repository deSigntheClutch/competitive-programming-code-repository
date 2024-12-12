#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << 1 << " ";
    for (int i = 2; i <= n; i++) {
      cout << i + (i - 1) << " ";
    }
    cout << endl;
  }
  return 0;
}
