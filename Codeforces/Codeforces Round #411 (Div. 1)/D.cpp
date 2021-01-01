#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, q;
int fa[N], f1[N], f2[N], f3[N], fi[N];
int diameter[N];
vector<int> G[N];
map<pair<int, int>, double> ans;

void init() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
  }
}

int find(int u) {
  if (fa[u] != u) return fa[u] = find(fa[u]);
  return fa[u];
}

void unite(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    fa[u] = v;
  }
}

void dfs(int u, int f) {
  f1[u] = 0;// sonL
  multiset<int> s;
  for (int x : G[u]) {
    if (x == f) continue;
    dfs(x, u);
    f1[u] = max(f1[u], f1[x] + 1);
    s.insert(f1[x] + 1);
  }
  for (int x : G[u]) {
    if (x == f) continue;
    s.erase(f1[x] + 1);
    if (s.size() == 0) f2[x] = 0;
    else f2[x] = *(--s.end());
    s.insert(f1[x] + 1);
  }
}

void dfs1(int u, int f) {
  for (int x : G[u]) {
    if (x == f) continue;
    f3[x] = max(f3[u] + 1, f2[x] + 1);
  }
  for (int x : G[u]) {
    if (x == f) continue;
    dfs1(x, u);
  }
}

void cal() {
  for (int i = 1; i <= n; i++) {
    if (find(i) != i) continue;
    dfs(i, -1);
    dfs1(i, -1);
  }
  for (int i = 1; i <= n; i++) {
    fi[i] = max(f3[i], max(f1[i], f2[i]));
    int k = find(i);
    diameter[k] = max(diameter[k], fi[i]);
  }
}

double Q(int u, int v) {
  if(u == v) return -1;
  if(u > v) swap(u, v);
  if(fabs(ans[make_pair(u, v)]) > 1e-9) return ans[make_pair(u, v)];

}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  init();
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
    unite(u, v);
  }
  cal();
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%.9f\n", Q(find(u), find(v)));
  }
  return 0;
}

