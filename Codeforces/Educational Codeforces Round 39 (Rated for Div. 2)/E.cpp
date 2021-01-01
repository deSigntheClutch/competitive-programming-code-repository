#include <bits/stdc++.h>
using namespace std;

string str;
int T;
int num[10];

bool check(string s) {
  bool zero = true;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] != '0') zero = false;
  }
  return s[0] && zero;
}

string cal(string s) {
  int n = s.length();
  int unsatisfied = 0;
  if (check(s)) {
    string res = "";
    for (int i = 0; i < n - 2; i++) {
      res += '9';
    }
    return res;
  }
  for (int i = 0; i < n; i++) {
    num[s[i] - '0'] ^= 1;
  }
  for (int j = 0; j < 9; j++) {
    unsatisfied += num[j];
  }
  if (unsatisfied == 0) return s;

  for (int i = n - 1; i >= 1; i--) {
    if (s[i + 1] == '0') {
      continue;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> str;
    cout << cal(str) << endl;
  }
  return 0;
}
