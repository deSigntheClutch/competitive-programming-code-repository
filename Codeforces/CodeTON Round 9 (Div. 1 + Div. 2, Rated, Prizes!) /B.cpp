#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

string s;

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;

    int n = s.length();
    string ans = "";
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        ans += s[i];
        ans += s[i + 1];
        break;
      }
    }
    if (ans == "") {
      for (int i = 0; i < n - 2; i++) {
        if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) {
          ans += s[i];
          ans += s[i + 1];
          ans += s[i + 2];
          break;
        }
      }
    }

    if (ans == "") cout << -1 << endl;
    else cout << ans << endl;
  }
  return 0;
}
