#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

long long n, d;
int T;
long long fact[N];

int main() {
      fact[1] = 1;
      for (int i = 2; i < 15; i++) {
            fact[i] = fact[i - 1] * i;
      }

      cin >> T;
      while (T--) {
            cin >> n >> d;

            cout << 1;

            if (n >= 3) cout << " " << 3;
            else {
                  if (fact[n] * d % 3 == 0)
                        cout << " " << 3;
            }

            if (d == 5) cout << " " << 5;

            if (n >= 3) {
                  if ((d + d * 10 + d * 100 + d * 1000 + d * 10000 + d * 100000) % 7 == 0) {
                        cout << " " << 7;
                  }
            } else {
                  if ((d + d * 10 + d * 100 + d * 1000) % 7 == 0) {
                        cout << " " << 7;
                  }
            }


            if (n >= 6) cout << " " << 9;
            else {
                  if ((fact[n] * d) % 9 == 0)
                        cout << " " << 9;
            }

            cout << endl;
      }
      return 0;
}
