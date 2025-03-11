#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e18 + 1;

int T;
int n, m;
int a[N];

int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            int gcd = 0;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  gcd = std::gcd(gcd, a[i]);
            }

            //cout << gcd << endl;
            for (int i = 1; i <= n; i++) {
                  a[i] /= gcd;
            }


            long long ans = 0;
            int cur = 0;

            for (int i = 1; i <= n; i++) {
                  int mn = INT_MAX;

                  for (int j = 1; j <= n; j++) {
                        mn = min(mn, std::gcd(cur, a[j]));
                  }

                  cur = mn;
                  ans += cur;

                  if (cur == 1) {
                        ans += n - i;
                        break;
                  }
            }

            cout << (long long)ans * gcd << endl;
      }
      return 0;
}
