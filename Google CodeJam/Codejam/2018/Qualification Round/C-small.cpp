#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int T;
  int A;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cin >> A;
    int x, y;
    bool flag = false;
    for (int i = 0; i < 330; i++) {
      cout << 10 << " " << 10 << endl;
      fflush(stdout);
      cin >> x >> y;
      if (x == 0 && y == 0) {
          flag = true;
          break;
      }
    }
    if(flag) continue;
    for (int i = 0; i < 330; i++) {
      cout << 10 << " " << 13 << endl;
      fflush(stdout);
      cin >> x >> y;
      if (x == 0 && y == 0) {
          flag = true;
          break;
      }
    }
    if(flag) continue;
    for (int i = 0; i < 330; i++) {
      cout << 10 << " " << 14 << endl;
      fflush(stdout);
      cin >> x >> y;
      if (x == 0 && y == 0) {
          flag = true;
          break;
      }
    }
  }
  return 0;
}
