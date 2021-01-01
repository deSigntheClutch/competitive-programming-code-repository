#include <bits/stdc++.h>
using namespace std;

const int N = 3E2 + 10;
const int MOD = 1E9 + 7;

long long f[N][N], g[N][N];
int n, m;

long long mod(long long b, long long v) {
  long long res = 1;
  while(v) {
    if(v) res = res * b % MOD;
    v >>= 1;
    b = b * b % MOD;
  }
  return res;
}

int main() {
  cin >> n >> m;
  g[1][0] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = i - 1; j <= m; j++) {
      f[i][j] =
    }
  }
  return 0;
}
