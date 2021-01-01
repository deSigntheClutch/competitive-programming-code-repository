#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int fa[2 * N];
int n, m, q, cnt = 0;
map<string, int> mp;

void init() {
  for (int i = 1; i <= n * 2; i++) {
    fa[i] = i;
  }
}

int find(int u) {
  if (fa[u] != u) return fa[u] = find(fa[u]);
  else return fa[u];
}

void uni(int u, int v) {
  u = find(u), v = find(v);
  if (u != v) {
    fa[u] = v;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> q;
  init();
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = ++cnt;
  }
  for (int i = 1; i <= m; i++) {
    int op;
    string s1, s2;
    cin >> op >> s1 >> s2;
    int u = mp[s1], v = mp[s2];
    if (op == 1) {
      if (find(u) == find(v + n) || find(v) == find(u + n)) {
        printf("NO\n");
      } else {
        uni(u, v), uni(u + n, n + v);
        printf("YES\n");
      }
    } else {
      if (find(u) == find(v) || find(v + n) == find(u + n)) {
        printf("NO\n");
      } else {
        uni(u, v + n), uni(u + n, v);
        printf("YES\n");
      }
    }
  }
  for (int i = 1; i <= q; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int u = mp[s1], v = mp[s2];
    if(find(u) == find(v) || find(u + n) == find(v + n)) {
      printf("1\n");
    } else if(find(u) == find(n + v) || find(v) == find(n + u)) {
      printf("2\n");
    } else {
      printf("3\n");
    }
  }
  return 0;
}

