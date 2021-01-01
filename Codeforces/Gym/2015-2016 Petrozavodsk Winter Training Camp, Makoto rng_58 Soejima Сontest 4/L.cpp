#include <bits/stdc++.h>
using namespace std;
 
const int N = 6123;
char s[N], t[N];
 
int main() {
  cin >> s >> t;
  int n = strlen(s);
  int n2 = strlen(t);
  if (s[0] != t[0] || n > n2) {
    puts("No");
    return 0;
  }
 
  int i = 0, j = 0;
  while (s[i] == s[i + 1]) ++i;
  while (t[j] == t[j + 1]) ++j;
 
  if (i < j) {
    puts("No");
    return 0;
  }
  j = 0;
  for (i = 0; i < n; i++) {
    while (s[i] != t[j] && j < n2) ++j;
    if (s[i] != t[j]) {
      puts("No");
      return 0;
    } else ++j;
  }
  puts("Yes");
  return 0;
}