#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2;

vector<int> G[N];
int n, m;
string s[N];

bool outBound[N][N];
int used[N][N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};


void dfs1(int x, int y, int v) {
      if (!(x >= 0 && x < n && y >= 0 && y < m)) return;

      if (used[x][y] != 0) return;

      used[x][y] = v;

      bool res = false;
      if (s[x][y] == 'U') {
            dfs1(x - 1, y, v);
            if (x - 1 >= 0)
                  res |= outBound[x - 1][y];
            else
                  res = true;
      } else if (s[x][y] == 'L') {
            dfs1(x, y - 1, v);
            if (y - 1 >= 0)
                  res |= outBound[x][y - 1];
            else
                  res = true;
      } else if (s[x][y] == 'R') {
            dfs1(x, y + 1, v);
            if (y + 1 < m)
                  res |= outBound[x][y + 1];
            else
                  res = true;
      } else if (s[x][y] == 'D') {
            dfs1(x + 1, y, v);
            if (x + 1 < n)
                  res |= outBound[x + 1][y];
            else
                  res = true;
      }
      //cout << x << " " << y << " " << res << endl;
      outBound[x][y] = res;
}

int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> n >> m;
            for (int i = 0; i < n; i++) {
                  cin >> s[i];
            }
            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        used[i][j] = 0;
                        outBound[i][j] = false;
                  }
            }

            int cnt = 1;
            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        if (s[i][j] != '?' && used[i][j] == 0) {
                              dfs1(i, j, cnt);
                              cnt += 1;
                        }
                  }
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        //cout << outBound[i][j];

                        if (s[i][j] != '?') {
                              ans += (outBound[i][j] != true);
                        }
                  }
                  //cout << endl;
            }
            //cout << ans << endl;
            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        if (s[i][j] == '?') {
                              bool check = false;
                              for (int dir = 0; dir < 4; dir++) {
                                    int tx = i + dx[dir];
                                    int ty = j + dy[dir];

                                    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
                                          if (s[tx][ty] == '?' || outBound[tx][ty] != true) {
                                                outBound[i][j] = true;
                                                check = true;
                                          }
                                    }
                              }
                              ans += check;
                        }
                  }
            }

            cout << ans << endl;
      }
      return 0;
}
