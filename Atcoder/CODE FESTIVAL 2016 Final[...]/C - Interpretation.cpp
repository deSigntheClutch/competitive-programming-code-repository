#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 10;

vector<int> language[N];

int n, m;
int fa[N], sz[N];

void init() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    sz[i] = 1;
  }
}

int find(int u) {
  if(fa[u] != u) return fa[u] = find(fa[u]);
  else return fa[u];
}

void uni(int a, int b) {
  a = find(a), b = find(b);
  if(a != b) {
    fa[a] = b;
    sz[b] += sz[a];
    sz[a] = sz[b];
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int k, v;
    scanf("%d", &k);
    for (int j = 1; j <= k; j++) {
      scanf("%d", &v);
      language[v].push_back(i);
    }
  }
  init();
  for(int i = 1; i <= m; i++) {
    if(language[i].size() <= 1) continue;
    for(int j = 0; j < language[i].size() - 1; j++) {
      uni(language[i][j + 1], language[i][j]);
    }
  }
  for(int i = 1; i <= n; i++) {
    if(sz[find(i)] != n) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
