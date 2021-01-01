#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int MOD = 1E9 + 7;

string s;

int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int len = s.length();
  int cnt = 0, ans = 0;
  for(int i = len - 1; i >= 0; i--) {
    if(s[i] == 'b') cnt = (cnt + 1) % MOD;
    else {
      ans = (ans + cnt) % MOD;
      cnt = 2 * cnt % MOD;
    }
  }
  printf("%d\n", ans);
  return 0;
}

