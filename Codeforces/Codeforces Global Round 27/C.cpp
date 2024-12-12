#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

bool check(int x) {
  while (x % 2 == 0)  {
    x /= 2;
  }
  return x == 1;
}

//int val(int x) {
//  int k = 0;
//  for (int i = 0; i < x; i++) {
//    if (i & 1) {
//      k |= a[i];
//    } else {
//      k &= a[i];
//    }
//  }
//  return k;
//}

int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;

    int len = 0, tmp = 1;
    for (;tmp <= n;) {
      tmp *= 2;
      len++;
    }
    len -= 1; tmp /= 2;

    if (n & 1) {
      if (n == 5) {
        cout << 5 << endl << "2 1 3 4 5" << endl;
      }
      else if (n == 7) {
        cout << 7 << endl << "2 4 5 1 3 6 7" << endl;
      }
      else {
        cout << n << endl;
        for (int i = 1; i < n; i++) {
          if (i == 1 || i == 3 || i == tmp - 2 || i == tmp - 1 || i == tmp) {continue;}
          cout << i << " ";
        }
        cout << "3 1 ";
        cout << tmp - 2 << " " << tmp - 1 << " " << tmp << " " << n << endl;
      }
    } else {
      if (check(n)) {
        cout << (1 << len + 1) - 1 << endl;

        for (int i = 1; i < n; i++) {
          if (i == 1 || i == 3 || i == tmp - 2 || i == tmp - 1) {continue;}
          cout << i << " ";
        }
        cout << "3 1 " << tmp - 2 << " " << tmp - 1 << " " << n << endl;
      } else {

        cout << (1 << len + 1) - 1 << endl;
        for (int i = 1; i < (1 << len) - 1; i++) {
          cout << i << " ";
        }
        for (int i = (1 << len); i <= n; i++) {
          cout << i << " ";
        }
        cout << (1 << len) - 1 << endl;
      }
    }
  }
  return 0;
}