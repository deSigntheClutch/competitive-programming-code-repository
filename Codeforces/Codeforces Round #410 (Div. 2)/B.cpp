#include <bits/stdc++.h>
using namespace std;

const int N = 55;

string a[N];
int n, b[N], len;

int check(int u, int v) {
  int res = -1;
  for (int i = 0; i < len; i++) {
    bool flag = true;
    for (int j = 0; j < len; j++) {
      if (a[u][j] != a[v][(i + j) % len]) flag = false;
    }
    if (flag) res = i;
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  len = a[0].length();
  b[0] = 0;
  for (int i = 1; i < n; i++) {
    if (check(0, i) == -1) {
      cout << -1 << endl;
      return 0;
    }
  }
  int res = 1e9 + 10;
  for (int i = 0; i < len; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      int tmp = 0;
      for (int k = 0; k < len; k++) {
        bool flag = true;
        for (int u = 0; u < len; u++) {
          if (a[0][(i + u) % len] != a[j][(k + u) % len]) flag = false;
        }
        if (flag) {
          tmp = k;
          break;
        }
      }
      cnt += tmp;
    }
    res = min(res, cnt);
  }
  cout << res << endl;
  return 0;
}
