#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

long long n;
int T;

int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            long long cnt = 1;
            while (n > 3) {
                  n = n / 4;
                  cnt *= 2;
            }
            cout << cnt << endl;
      }
      return 0;
}
