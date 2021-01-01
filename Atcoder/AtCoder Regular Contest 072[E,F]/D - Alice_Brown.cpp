#include <bits/stdc++.h>
using namespace std;

const int N = 500;

int sg[N][N];

int dfs(int u, int v) {
  if (sg[u][v] != -1) return sg[u][v];
  set<int> s;
  for (int i = 1; 2 * i <= u; i++) {
    s.insert(dfs(u - 2 * i, i + v));
  }
  for (int i = 1; 2 * i <= v; i++) {
    s.insert(dfs(u + i, v - 2 * i));
  }
  for (int i = 0;; i++) {
    if (s.find(i) == s.end()) {
      return sg[u][v] = i;
    }
  }
}
long long x, y;
int main() {
  memset(sg, -1, sizeof sg);
  sg[0][0] = sg[0][1] = sg[1][0] = sg[1][1] = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      dfs(i, j);
      //  printf("%d ", sg[i][j]);
    }
    // printf("\n");
  }
  cin >> x >> y;
  if (abs(x - y) <= 1) cout << "Brown" << endl;
  else cout << "Alice" << endl;
  return 0;
}

