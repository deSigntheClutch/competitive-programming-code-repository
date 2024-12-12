#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

const int N = 3e5 + 19;
const int M = 1e7 + 2;

int T;
int n, a[N];
int notPrime[M];
int sg[M];

void init() {
  fill(sg, sg + M, -1);
  sg[0] = 0;
  sg[1] = 1;
  sg[2] = 0;

  int ordPrime = 2;
  for (int i = 3; i < M; i++) {
    if (i % 2 == 0) {
      sg[i] = 0;
      continue;
    }

    if (notPrime[i] == -1) continue;
    notPrime[i] = ordPrime++;
    sg[i] = notPrime[i];
    for (int j = i * 2; j < M; j += i) {
      notPrime[j] = -1;
      if (sg[j] == -1) sg[j] = notPrime[i];
    }
  }
}

int main() {
  init();

  cin >> T;
  while (T--) {
    cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ans ^= sg[a[i]];
    }

    if (ans != 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
  }
  return 0;
}
