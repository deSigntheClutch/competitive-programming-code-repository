#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int m, d;
int a[N];

int main() {
      cin >> m >> d;
      int cnt = 0;
      for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= d; j++) {
                  int d1 = j % 10, d2 = j / 10;
                  if (d1 >= 2 && d2 >= 2 && d1 * d2 == i) {
                        cnt += 1;
                  }
            }
      }
      cout << cnt << endl;
      return 0;
}