#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int N = 2e5 + 10;
int p[N];

int main() {
  int T, n;
  cin >> T;
  for (int cs = 0; cs < T; cs++) {
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      ans = max(ans, abs(p[i] - i));
    }
    if (ans <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
