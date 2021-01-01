#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int vis[N], n, m;
char str[N];

int main() {
  scanf("%d", &m);
  scanf("%s", str + 1);
  n = strlen(str + 1);
  for (int ch = 'a'; ch <= 'z'; ch++) {
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; i++) {
      if ((int)str[i] < ch) vis[i] = 1;
    }
    vector<int> choice;
    bool flag = true;
    int used = 0;
    int lastch = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) {
        used = i;
        continue;
      } else {
        if (ch == str[i]) lastch = i;
        if (i - used == m) {
          used = lastch;
          if (i - used >= m) {
            flag = false;
            break;
          }
          choice.push_back(lastch);
        }
      }
    }
    if (flag) {
      vector<char> ans;
      for (int i = 1; i <= n; i++) {
        if (ch > str[i]) ans.push_back(str[i]);
      }
      for (int i = 0; i < (int) choice.size(); i++) {
        ans.push_back(ch);
      }
      sort(ans.begin(), ans.end());
      for (char x : ans) {
        cout << x ;
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}

