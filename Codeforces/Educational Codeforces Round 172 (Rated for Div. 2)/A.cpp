#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 2e9;

int T, n, k;
int a[N];
vector<long long> v;

int main() {
      cin >> T;
      while (T--) {
            cin >> n >> k;

            for (int i = 0; i < n; i++) cin >> a[i];

            sort(a, a + n);

            int ans = INF;
            int sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                  sum += a[i];
                  if (sum == k) {
                        ans = 0;
                        break;
                  }
            }

            sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                  sum += a[i];

                  if (sum > k) break;

                  ans = min(ans, k - sum);
            }

            cout << ans << endl;
      }
}
