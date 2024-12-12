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
    if (n & 1) {
      if (n >= 27) {
        int ask = 2;
        p[1] = 1;
        p[10] = 1;
        p[26] = 1;
        for (int i = 2; i <= 9; i++) {
          p[i] = ask;
          if (i & 1) ask += 1;
        }
        for (int i = 12; i <= 25; i++) {
          p[i] = ask;
          if (i & 1) ask += 1;
        }
        p[11] = ask;
        p[27] = ask;
        ask += 1;
        for (int i = 28; i <= n; i++) {
          p[i] = ask;
          if (i & 1) ask += 1;
        }

        for (int i = 1; i <= n; i++) {
          cout << p[i] << " ";
        }
        cout << endl;
      }
      else cout << -1 << endl;
    }
    else {
      int ask = 1;
      for (int i = 0; i < n; i++) {
        cout << ask << " ";
        if (i & 1) ask += 1;
      }
      cout << endl;
    }
  }
  return 0;
}
