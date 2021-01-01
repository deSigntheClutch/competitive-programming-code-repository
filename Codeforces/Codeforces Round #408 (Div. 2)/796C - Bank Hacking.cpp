#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt<<1,left,mid
#define rson rt<<1|1,mid+1,right

const int N = 3E5 + 10;

int n, l = 1;
int a[N], t[N << 2];
vector<int> G[N];

void pushup(int rt) {
  t[rt] = max(t[rt << 1 | 1], t[rt << 1]);
}

void build(int rt, int left, int right) {
  if (left == right) {
    scanf("%d", &a[l++]);
    t[rt] = a[l - 1] + 2;
    return ;
  }
  build(lson);
  build(rson);
  pushup(rt);
}

void update(int rt, int left, int right, int id, int v) {
  if (id == left && left == right) {
    t[rt] += v;
    return;
  }
  if (mid >= id) update(lson, id, v);
  else update(rson, id, v);
  pushup(rt);
}


int main() {
  scanf("%d", &n);
  build(1, 1, n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  int ans = 2e9 + 10;
  for (int i = 1; i <= n; i++) {
    update(1, 1, n, i, -2);
    for (int v : G[i]) {
      update(1, 1, n, v, -1);
    }
    ans = min(ans, t[1]);
    update(1, 1, n, i, 2);
    for (int v : G[i]) {
      update(1, 1, n, v, 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
