#include "bits/stdc++.h"
using namespace std;
 
const int N = 2E3 + 5;
 
bool vis[N][N];
int n;
 
void solve(int x, int y, int p, int q) {
  if (x > p) swap(x, p), swap(y, q);
  if (x == p || y == q) return ;
  long double delta = 1.0 * (q - y) / (p - x);
  long double cur_y = y, last_y = 0;
  for (int i = x + 1; i <= p; i++) {
    last_y = cur_y, cur_y += delta;
    if (fabs(cur_y - round(cur_y)) < 1e-9) cur_y = round(cur_y);
    if (delta < 0) {
      int bound = (int) floor(cur_y);
      for (int j = (int)ceil(last_y) - 1; j >= bound; j--) vis[i][j + 1] = true;
    } else {
      int bound = (int) floor(cur_y);
      for (int j = (int)floor(last_y); j < (int)ceil(cur_y); j++) vis[i][j + 1] = true;
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x[2], y[2];
    cin >> x[0] >> y[0] >> x[1] >> y[1];
    solve(x[0], y[0], x[1], y[1]);
  }
  int ans = 0;
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= 2000; j++) {
      ans += vis[i][j];
    }
  }
  cout << ans << endl;
  return 0;
}