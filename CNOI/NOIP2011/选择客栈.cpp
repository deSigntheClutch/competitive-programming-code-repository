#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int K = 55;

int n, k, p;
vector<int> shop[K];
int a[N], b[N];

int main() {
      cin >> n >> k >> p;

      for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
      }

      int closest_p = 0;
      long long ans = 0;
      for (int i = 1; i <= n; i++) {
            if (b[i] <= p) {
                  closest_p = i;
            }
            int cnt = upper_bound(shop[a[i]].begin(), shop[a[i]].end(), closest_p) - shop[a[i]].begin();
            ans += cnt;
            shop[a[i]].push_back(i);
      }

      cout << ans << endl;
      return 0;
}