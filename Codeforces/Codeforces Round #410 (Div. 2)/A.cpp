#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

string s;

int main() {
  cin >> s;
  int len = s.length();
  if (len & 1) {
    int cnt = 0;
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - 1 - i]) cnt++;
    }
    if (cnt <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  } else {
    int cnt = 0;
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - 1 - i]) cnt++;
    }
    if (cnt == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}


