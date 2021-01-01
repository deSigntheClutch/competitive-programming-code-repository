#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k;
int a[N];
bool f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  f[0][0] = 1;
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {

    }
  }
  return 0;
}

