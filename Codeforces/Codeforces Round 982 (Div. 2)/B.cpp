#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 4;
const int INF = 1e9 + 10;

int T, n;
int a[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    int ans = n - 1;
    map<int, int> vis;
    for (int i = 1; i <= n; i++) {
      int c = 0;
      if (vis[a[i]]) continue;
      vis[a[i]] = true;

      for (int j = i + 1; j <= n; j++) {
        c += a[j] > a[i];
      }

      ans = min(i - 1 + c, ans);
    }
    cout << ans << endl;
  }
  return 0;
}
