#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right


int main() {
  int T;
  long long n, m, r, c;

  cin >> T;
  while (T--) {
    cin >> n >> m >> r >> c;
    cout << m - c + (n - r) * m + (n - r) * (m - 1) << endl;
  }
  return 0;
}
