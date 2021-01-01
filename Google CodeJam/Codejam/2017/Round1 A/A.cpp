#include <bits/stdc++.h>
using namespace std;

const int N = 30;
int n, m;
char s[N][N];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int cs = 1; cs <= T; cs++) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s[i] + 1);
    }
    int bound = 1;
    for (int c = 1; c <= m; c++) {
      vector<int> pos;
      for (int r = 1; r <= n; r++) {
        if (s[r][c] == '?') continue;
        pos.push_back(r);
      }
      if ((int)pos.size() == 0) continue;
      int t = 0;
      for (int x : pos) {
        for (int i = t + 1; i <= x; i++) {
          for (int j = bound; j <= c; j++) {
            s[i][j] = s[x][c];
          }
        }
        t = x;
      }
      for (int i = t + 1; i <= n; i++) {
        for (int j = bound; j <= c; j++) {
          s[i][j] = s[t][c];
        }
      }
      bound = c + 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if(s[i][j] == '?') {
          s[i][j] = s[i][j - 1];
        }
      }
    }
    printf("Case #%d:\n", cs);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        printf("%c", s[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}

