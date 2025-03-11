#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e2 + 3;

char board[N][N];
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<int> G[N * N];
int root[N];
bool used[N][N];

bool valid(int x, int y) {
      if (x >= 1 && x <= n && y >= 1 && y <= m && board[x][y] != '#') {
            return true;
      }
      return false;
}

int id(int x, int y) {
      return (x - 1) * m + y;
}

void dfs(int u, int v) {
      G[]
}

signed main() {
      cin >> n >> m;
      for (int i = 1; i <= n; i++) {
            cin >> (board[i] + 1);
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if (board[i][j] == '<') {
                        if (valid(i, j - 1)) {
                              G[id(i, j)].push_back(id(i, j - 1));
                        }
                  } else if (board[i][j] == '>') {
                        if (valid(i, j + 1)) {
                              G[id(i, j)].push_back(id(i, j + 1));
                        }
                  } else if (board[i][j] == '^') {
                        if (valid(i - 1, j)) {
                              G[id(i, j)].push_back(id(i - 1, j));
                        }
                  } else if (board[i][j] == 'v') {
                        if (valid(i + 1, j)) {
                              G[id(i, j)].push_back(id(i + 1, j));
                        }
                  }
            }
      }

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                  if (!used[i][j]) {
                        dfs(i, j);
                  }
            }
      }
      return 0;
}
