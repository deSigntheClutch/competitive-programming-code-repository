#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const int INF = 1e9 + 7;

int l, w;
int b[N], a[N];
int sum[N];

int main() {
      ios::sync_with_stdio(false);
      cin >> w >> l;
      for (int i = 1; i < w; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
      }

      int ans = INF;
      for (int i = l; i < w; i++) {
            ans = min(ans, sum[i] - sum[i - l]);
      }
      cout << ans << endl;
      return 0;
}
