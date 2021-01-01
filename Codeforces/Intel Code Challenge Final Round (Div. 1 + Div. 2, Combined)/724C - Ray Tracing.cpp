#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const long long INF = 1e18 + 10;

int ans[N];
long long x[N], y[N], n, m;
pair<long long, int> p[N];
int k;

long long extgcd(long long &x, long long &y, long long a, long long b) {
  if(b)
}

int main() {
  ios::sync_with_stdio(false);
  memset(ans, -1, sizeof ans);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
    p[i] = make_pair(cal(i), i);
  }
  sort(p + 1, p + 1 + k);
  int cnt = 1;
  for (int i = 1; i <= k; i++) {
    if (p[i].first >= INF) continue;
    ans[p[i].second] = cnt;
    cnt++;
  }
  for (int i = 1; i <= k; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

