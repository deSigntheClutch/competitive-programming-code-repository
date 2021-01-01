#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int s = 1e6;

int x[N], n;
bool vis[N];
vector<int> ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", x + i);
    vis[x[i]] = 1;
  }
  int cnt_pair = 0;
  for (int i = 1; i <= s; i++) {
    if (vis[i] == 1 && vis[s + 1 - i] != 1) ans.push_back(s + 1 - i);
    else if(vis[i] == 1 && vis[s + 1 - i] == 1) cnt_pair++;
  }
  cnt_pair /= 2;
  for (int i = 1; i <= s / 2; i++) {
    if (cnt_pair == 0) continue;
    else {
      if (vis[i] == 0 && vis[s + 1 - i] == 0) {
        ans.push_back(i);
        ans.push_back(s + 1 - i);
        cnt_pair--;
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (int v : ans) {
    printf("%d ", v);
  }
  printf("\n");
  return 0;
}
