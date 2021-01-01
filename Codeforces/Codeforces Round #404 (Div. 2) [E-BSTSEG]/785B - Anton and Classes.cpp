#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> x, y;
int n, m;
int l[N], r[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    x.push_back(u), y.push_back(v);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    ans = max(ans, max(0, l[i] - y[0]));
    ans = max(ans, max(0, x[m - 1] - r[i]));
  }
  cout << ans << endl;
  return 0;
}


