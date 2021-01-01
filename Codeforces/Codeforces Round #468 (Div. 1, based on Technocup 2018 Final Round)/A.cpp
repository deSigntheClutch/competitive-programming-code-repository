#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> G[N];
int p[N];
int n;
int sz[N];

void dfs(int u, int d) {
  sz[d] ^= 1;
  for(int x : G[u]) {
    dfs(x, d + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    G[p[i]].push_back(i);
  }
  dfs(1, 0);
  int cnt = 0;
  for(int i = 0; i < N; i++) {
    cnt += sz[i];
  }
  cout << cnt << endl;
  return 0;
}
