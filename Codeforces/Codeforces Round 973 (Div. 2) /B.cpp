#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e18 + 1;

int n, m;
int T;
long long a[N];

int main() {
      cin >> T;
      while (T--) {
            cin >> n;

            long long sum = 0;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  if (i < n - 1) sum += a[i];
            }

            cout << a[n] + sum - a[n - 1] << endl;
      }
      return 0;
}
