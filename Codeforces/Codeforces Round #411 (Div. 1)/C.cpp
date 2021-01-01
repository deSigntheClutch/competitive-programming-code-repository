#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define debug0(x) printf("! %d\n", x);
#define debug1(x, a, b) for(int (ii)=(a);(ii)<(b);(ii++)) printf("%d: %d\n", ii, x[ii]);
#define nono(x, ite) for(__typeof((x).begin()) (ite)=(x).begin();(ite)!=(x).end();(ite++))

typedef long long ll;

const int N = 3e5 + 10;

int fa[N], ans[N];
int n, m;
vector<int> col[N];
vector<int> G[N];

void init() {
  for (int i = 1; i <= m; i++) {
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
  set<int> s;
  for (int t : col[u]) {
    if (ans[t] != 0) {
      s.insert(ans[t]);
    }
  }
  int cnt = 1;
  for (int t : col[u]) {
    if (ans[t] == 0) {
      while (s.find(cnt) != s.end()) cnt++;
      ans[t] = cnt;
      s.insert(cnt);
    }
  }
  for (int x : G[u]) {
    if (f == x) continue;
    dfs(x, u);
  }
}

int main() {
  multiset<int> s;
  s.insert(0);
  s.insert(1);
  s.insert(7);
  cout << * (--s.end()) << endl;
  return 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    for (int j = 0; j < v; j++) {
      int t;
      scanf("%d", &t);
      col[i].push_back(t);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  init();
  int mx = 1;
  dfs(1, -1);
  for(int i = 1 ; i <= m; i++) {
    if(ans[i] == 0) {
      ans[i] = 1;
    }
  }
  printf("%d\n", *max_element(ans + 1, ans + 1 + m));
  for (int i = 1; i <= m; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}

