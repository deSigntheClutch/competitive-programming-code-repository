#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const long long INF = 9e18 + 10;

int n;
long long c, a[N], b[N];
long long f[2][N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    f[0][i] = INF;
  }
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    fill(f[i & 1], f[i & 1] + i + 2, INF);
    for (int j = 0; j <= i; j++) {
      f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][j] + a[i] + j * c);
      if(j >= 1) f[i & 1][j] = min(f[i & 1][j], f[i & 1 ^ 1][j - 1] + b[i]);
    }
  }
  cout << *min_element(f[n & 1], f[n & 1] + 1 + n) << endl;
  return 0;
}

