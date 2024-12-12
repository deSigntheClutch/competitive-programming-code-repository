#include <iostream>
#include <algorithm>
using namespace std;

long long x, m;

long long cal(long long bound) {
  long long cnt = (m - bound) / x;
  if (cnt < 0) cnt = 0;

  // xor = 0
  if (m - bound + 1 > 0) cnt += 1;

  // xor = x
  if (m - bound >= x) cnt -= 1;

  long long left_bound = m - bound + 1;
  if (left_bound < 0) left_bound = 0;

  for (long long xorXY = left_bound; xorXY <= m + bound; xorXY++) {
    long long y = x ^ xorXY;
    if (y >= 1 && y <= m && (xorXY % x == 0)) {
      cnt += 1;
    }
  }
  return cnt;
}


int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> x >> m;
    long long bound = 1;
    while (bound <= x) {
      bound <<= 1;
    }
    //cout << "bound = " << bound << endl;
    long long cntY = 0, cntXY = 0;
    long long right_bound = m > bound ? bound : m;
    for (long long i = 1; i <= right_bound; i++) {
      long long xorXY = x ^ i;
      if (xorXY % i == 0) {
        //cout << "2: " << i << endl;
        cntY += 1;
      }
      if (xorXY % i == 0 && xorXY % x == 0) {
        //cout << "3: " << i << endl;
        cntXY += 1;
      }
    }
    //cout << cal(bound) << " " << cntXY << " " << cntY << endl;
    cout << cal(bound) + cntY - cntXY << endl;
  }
  return 0;
}
