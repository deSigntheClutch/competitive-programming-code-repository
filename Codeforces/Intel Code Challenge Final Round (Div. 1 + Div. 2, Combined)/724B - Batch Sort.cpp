#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 10;

int n, m;
int a[N][N];

void _swap(int u, int v) {
  for (int i = 1; i <= n; i++) {
    swap(a[i][u], a[i][v]);
  }
}

bool check() {
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != j) {
        cnt++;
      }
    }
    if (!(cnt == 0 || cnt == 2)) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  if (check()) cout << "YES" << endl;
  else {
    for (int i = 1; i <= m; i++) {
      for (int j = i + 1; j <= m; j++) {
        _swap(i, j);
        if (check()) {
          cout << "YES" << endl;
          return 0;
        }
        _swap(i, j);
      }
    }
    cout << "NO" << endl;
  }
  return 0;
}

