#include <bits/stdc++.h>
using namespace std;

long long N, M;

long long c(long long u) {
  long long res = 1;
  while (u--) {
    res <<= 1;
  }
  return res;
}

int main() {
  cin >> N >> M;
  if (N >= 60) cout << M << endl;
  else {
    cout << M % c(N) << endl;
  }
  return 0;
}

