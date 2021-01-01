#include <bits/stdc++.h>
using namespace std;

long long x;

int main() {
  cin >> x;
  if (x % 11 == 0) cout << 2 * (x / 11) << endl;
  else cout << 2 * (x / 11) + ((x % 11 > 6) ? 2 : 1) << endl;
  return 0;
}
