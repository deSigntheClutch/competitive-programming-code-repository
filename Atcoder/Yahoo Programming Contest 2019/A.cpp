#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int ans = (n + 1) / 2;
  if (ans >= k) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
