#include <iostream>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;

int T;
int a,b,c,d;

int main() {
  cin >> T;
  while (T--) {
    cin >> a >> b >> c >> d;
    if (a > c) {
      swap(a, c);
      swap(b, d);
    }
    if (b < c) {
      cout << 1 << endl;
    } else if (a <= c && c <= b && b < d) {
      cout << b - c + (c - 1 >= a) + (b + 1 <= d) << endl;
    } else if (a <= c && d <= b) {
      cout << d - c + (c - 1 >= a) + (d + 1 <= b) << endl;
    }
  }
  return 0;
}
