#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const int INF = 1e9 + 10;

int T, n, q;
pair<int, int> p[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
      cin >> p[i].first >> p[i].second;
      a = max(a, p[i].second);
      b = max(b, p[i].first);
    }
    cout << a + b + a + b << endl;
  }
  return 0;
}
