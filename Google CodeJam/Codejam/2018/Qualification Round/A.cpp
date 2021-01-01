#include <bits/stdc++.h>
using namespace std;

string P;
long long D, n;

bool check() {
  long long res = 0;
  for (int i = 0; i < P.length(); i++) {
    if (P[i] == 'S') res++;
  }
  return res <= D;
}

long long cal() {
  long long res = 0;
  long long C = 1;
  for (int i = 0; i < n; i++) {
    if (P[i] == 'S') res += C;
    else C <<= 1;
  }
  return res;
}

int getLastS() {
  for (int i = n - 1; i >= 0; i--) {
    if (P[i] == 'S') {
      return i;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cout << "Case #" << cs << ": ";
    cin >> D;
    cin >> P;
    n = P.length();
    if (!check()) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    int ans = 0;
    while (cal() > D) {
      int lastS = getLastS();
      while(lastS >= 0 && P[lastS] == 'S') lastS--;
      swap(P[lastS], P[lastS + 1]);
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

