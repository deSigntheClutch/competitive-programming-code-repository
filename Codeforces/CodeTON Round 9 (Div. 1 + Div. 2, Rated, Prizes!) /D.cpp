#include <iostream>
#include <numeric>
using namespace std;

const int N = 1e5 + 5;

int n, m;
int a[N];
int x[N];

//bool check() {
//  int n = 7;
//  int a[10] = {-1, 6, 4, 4, 3, 4, 3, 4, 3, 3};
//
//  for (int i = 1; i <= n; i++) {
//    for (int j = i + 1; j <= n; j++) {
//      if (a[std::gcd(i, j)] == std::gcd(a[i], a[j])) {
//        return false;
//      }
//    }
//  }
//  return true;
//}


int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      cin >> a[i];
    }
    fill(x, x + n + 1, 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 2 * i; j <= n; j += i) {
        x[j] = max(x[j], x[i] + 1);
      }
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
      //cout << x[i] << " ";
      if (x[i] > m - 1) {
        flag = false;
      }
    }
    //cout << endl;

    if (flag) {
      for (int i = 1; i <= n; i++) {
        cout << a[m - x[i]] << " ";
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
