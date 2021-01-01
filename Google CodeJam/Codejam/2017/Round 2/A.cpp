#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;

int n, p;
int a[N];

int main() {
  ios::sync_with_stdio(false);
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (p == 2) {
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] & 1) cnt++;
      }
      if (cnt & 1) cout << n - (cnt - 1) / 2 << endl;
      else cout << n - cnt / 2 << endl;
    } else if (p == 3) {
      int cnt1 = 0, cnt2 = 0;
      for (int i = 1; i <= n; i++) {
        if (a[i] % 3 == 1) cnt1++;
        else if (a[i] % 3 == 2) cnt2++;
      }
      int t = min(cnt1, cnt2);
      int ans = t;
      cnt1 -= t, cnt2 -= t;
      if (cnt1 != 0) ans += 2 * (cnt1 / 3) + max(0, (cnt1 % 3) - 1);
      if (cnt2 != 0) ans += 2 * (cnt2 / 3) + max(0, (cnt2 % 3) - 1);
      cout << n - ans << endl;
    } else if (p == 4) {
      int cnt[10];
      memset(cnt, 0, sizeof cnt);
      for (int i = 1; i <= n; i++) {
        if (a[i] % 4 == 1) cnt[1]++;
        else if (a[i] % 4 == 2) cnt[2]++;
        else if (a[i] % 4 == 3) cnt[3]++;
      }
      int ans = 0;
      int minx = min(cnt[1], cnt[3]);
      ans += minx;
      cnt[1] -= minx, cnt[3] -= minx;
      int cur = max(cnt[1], cnt[3]);
      ans += cnt[2] / 2;
      cnt[2] %= 2;
      int left = cur % 4;
      ans += 3 * (cur / 4);
      if(cnt[2] == 0) ans += max(0, left - 1);
      else {
          if(left == 3) ans += max(0, left - 1);
          else ans += max(left, 0);
      }
      cout << n - ans << endl;
    }
  }
  return 0;
}


