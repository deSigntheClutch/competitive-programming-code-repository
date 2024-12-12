#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right


int main() {
  int T;
  long long n;

  cin >> T;
  while (T--) {
    cin >> n;

    if (n % 2 == 0) {
      string ans = "";
      for (int i = 1; i <= n - 2; i++) {
        ans += "3";
      }
      cout << ans + "66" << endl;
    } else {
      if (n == 1 || n == 3) {
        cout << -1 << endl;
      } else {
        string ans = "";
        for (int i = 1; i <= n - 4; i++) {
            ans += "3";
        }


        cout << ans + "6366" << endl;
      }
    }
  }
  return 0;
}
