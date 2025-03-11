#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, cnt;

int main() {
      cin >> a >> b;

      while (a > b) {
            if (a & 1) {
                  a += 1;
                  a /= 2;
                  cnt += 2;
            } else {
                  a /= 2;
                  cnt += 1;
            }
      }

      cout << cnt + (b - a) << endl;
      return 0;
}
