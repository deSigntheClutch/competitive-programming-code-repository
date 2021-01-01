#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> C;

int main() {
  ios::sync_with_stdio(false);
  int sum  =0;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
    sum += a[i];
  }
  bool flag = false;
  for (int i = 1; i < (1 << 4) - 1; i++) {
      int cur = 0;
      for (int j = 0; j < 4; j++) {
          if (i >> j & 1) continue;
          cur += a[j];
      }
      if (sum - cur == cur) flag = true;
  }
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
