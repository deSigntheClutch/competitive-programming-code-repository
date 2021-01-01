#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

int n, a[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  int len = unique(a + 1, a + 1 + n) - (a + 1);
  if((n - len) % 2) cout << len - 1 << endl;
  else cout << len << endl;
  return 0;
}
