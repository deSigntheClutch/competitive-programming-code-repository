#include <bits/stdc++.h>
using namespace std;

#define mid ((left + right) >> 1)

const int N = 3e5 + 10;
const int LOG_N = 20;

struct Node {
  int l, r;
  int v;
} t[N * LOG_N * LOG_N];

int n, m;
int root[N], ord[N], sz;
vector<int> Q[N];

int Insert(int rt, int left, int right, int u) {
  int id = ++sz;
  t[id] = t[rt], t[id].v += 1;
  if(left == right) return id;
  if (mid >= u) t[id].l = Insert(t[id].l, left, mid, u);
  else if (mid < u) t[id].r = Insert(t[id].r, mid + 1, right, u);
  return id;
}

int Query(int rt, int left, int right, int l, int r) {
  if(!rt || l > r) return 0;
  if(left == l && r == right) return t[rt].v;
  if(mid >= r) return Query(t[rt].l, left, mid, l, r);
  else if(mid < l) return Query(t[rt].r, mid + 1, right, l, r);
  else return Query(t[rt].l, left, mid, l, mid) + Query(t[rt].r, mid + 1, right, mid + 1, r);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    Q[r].push_back(l);
  }
  for (int i = 1; i <= m; i++) {
    sort(Q[i].begin(), Q[i].end());
  }
  int cnt = 1, nxt = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < Q[i].size(); j++) {
      root[cnt] = Insert(root[cnt - 1], 1, m, Q[i][j]);
      cnt++;
    }
    ord[i] = cnt - 1;
  }
  for (int i = 1; i <= m; i++) {
    int ans = 0;
    for (int j = i; j <= m; j += i) {
      ans += Query(root[ord[min(m, j + i - 1)]], 1, m, 1, j) - Query(root[ord[j - 1]], 1, m, 1, j - 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
/*



3 3
1 2
2 3
3 3

*/
