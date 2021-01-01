#include <bits/stdc++.h>
using namespace std;

string state;
int k;

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cin >> state >> k;
    int cnt = 0, len = state.length();
    for (int i = 0; i <= len - k; i++) {
      if (state[i] == '+') continue;
      if (i + k - 1 >= len) continue;
      cnt++;
      for (int j = i; j <= i + k - 1; j++) {
        if (state[j] == '-') state[j] = '+';
        else state[j] = '-';
      }
    }
    bool flag = true;
    for (int i = 0; i < state.length(); i++) {
      if (state[i] == '-') flag = false;
    }
    if (flag == false) cout << "Case #" << cs << ": " << "IMPOSSIBLE" << endl;
    else cout << "Case #" << cs << ": " << cnt << endl;
  }
  return 0;
}

