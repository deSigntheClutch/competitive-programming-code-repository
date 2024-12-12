#include <iostream>
#include <vector>
using namespace std;

long long x, m;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> x >> m;

    long long bound = 1;
    while (bound <= x) {
      bound <<= 1;
    }

    int cnt = 0;
    for (int i = 1; i <= min(m, bound); i++) {
      if (x == i) continue;
      long long res = i ^ x;
      if (i % res == 0 || x % res == 0) {
        cnt += 1;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
