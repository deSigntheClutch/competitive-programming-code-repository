#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 3;
const int INF = 1e9 + 7;

int n, m, k;
int w[N][N];
int f[N][N];

void init() {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= max(m, k); j++) {
      w[i][j] = INF;
      f[i][j] = INF;
    }
  }
}

void proc(int idx, string s) {
  vector<int> v;
  v.push_back(0);
  for (int i = 0; i < m; i++) {
    if (s[i] == '1') {
      v.push_back(i + 1);
    }
  }
  v.push_back(m + 1);
  int sz = (int)v.size();
  for (int i = 0; i <= k; i++) {
    if (i >= sz - 2) {
      w[idx][i] = 0;
      continue;
    }
    for (int j = 0; j <= i; ++j) {
      w[idx][i] = min(w[idx][i], v[sz - 2 - (i - j)] - v[j + 1] + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  init();
  for (int i = 1; i <= n; ++i) {
    string str;
    cin >> str;
    proc(i, str);
  }
  f[0][k] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (f[i][j] != INF) {
        for (int x = 0; x <= j; x++) {
          f[i + 1][j - x] = min(f[i + 1][j - x], f[i][j] + w[i + 1][x]);
        }
      }
    }
  }
  int ans = INF;
  for (int i = 0; i <= k; i++) {
    ans = min(ans, f[n][i]);
  }
  cout << ans << endl;
  return 0;
}
