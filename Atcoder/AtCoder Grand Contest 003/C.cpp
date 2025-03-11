#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 1;
int n, a[N];

signed main() {
      cin >> n;

      vector<int> p, q, val;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            val.push_back(a[i]);
      }
      sort(val.begin(), val.end());

      for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin() + 1;
            if (i & 1) p.push_back(a[i]);
            else q.push_back(a[i]);
      }
      sort(p.begin(), p.end());
      sort(q.begin(), q.end());

      int cnt = 0;
      for (auto x : p) {
            if (x % 2 == 0) cnt += 1;
      }
      cout << cnt << endl;
      return 0;
}