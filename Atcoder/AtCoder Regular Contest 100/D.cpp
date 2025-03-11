#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
long long sum[N];

long long cal(int i, int j, int k) {
      vector<long long> v;
      v.push_back(sum[i]);
      v.push_back(sum[j] - sum[i]);
      v.push_back(sum[k] - sum[j]);
      v.push_back(sum[n] - sum[k]);
      sort(v.begin(), v.end());
      return v[3] - v[0];
}


int main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
      }

      int p = 1, r = 3;
      long long ans = 1e18;
      for (int q = 2; q <= n - 2; q++) {
            ans = min(ans, cal(p, q, r));
            while (r < n && abs((sum[r] - sum[q]) - (sum[n] - sum[r])) > abs((sum[r + 1] - sum[q]) - (sum[n] - sum[r + 1]))) {
                  r += 1;
                  ans = min(ans, cal(p, q, r));
            }
            while (p < q && abs((sum[q] - sum[p]) - sum[p]) > abs((sum[q] - sum[p + 1]) - sum[p + 1])) {
                  p += 1;
                  ans = min(ans, cal(p, q, r));
            }
      }
      cout << ans << endl;
      return 0;
}