#include <bits/stdc++.h>
using namespace std;

const int N = 55 + 10;
int a[N][N];

int main() {
  int n;
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 1) {
        bool flag = false;
        for (int x = 0; x < n; x++) {
          for (int y = 0; y < n; y++) {
            if (a[i][j] == a[i][x] + a[y][j]) {
              flag = true;
            }
          }
        }
        if (flag == false) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}

