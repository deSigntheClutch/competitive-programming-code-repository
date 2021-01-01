#include <bits/stdc++.h>
using namespace std;

int cnt[200][200];
int n;
string s;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.length(); j++) {
      cnt[i][(int)s[j]]++;
    }
  }
  for(int i = 'a'; i <= 'z'; i++) {
    int mx = 1e9 + 10;
    for(int j = 0; j < n; j++) {
      mx = min(mx, cnt[j][i]);
    }
    for(int j = 0; j < mx; j++) {
      printf("%c", (char)i);
    }
  }
  puts("");
  return 0;
}
