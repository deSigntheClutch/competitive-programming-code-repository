#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 26 - 1;

int n;

int main() {
      int T; cin >> T; while(T--) {
            cin >> n;
            int ans = (n % 15 > 2) ? 3 : n % 15 + 1;
            cout << 3 * (n/15) + ans << endl;
      }
      return 0;
}
