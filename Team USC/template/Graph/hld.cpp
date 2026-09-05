vector<int> G[N];
int n, m, len;
int fa[20][N], sz[N], depth[N], top[N], id[N];
ll t[N << 2], lazy[N << 2];

void dfs1(int u, int f, int d) {
  depth[u] = d;
  fa[0][u] = f;
  sz[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    if (f == G[u][i]) continue;
    dfs1(G[u][i], u, d + 1);
    sz[u] += sz[G[u][i]];
  }
}

void dfs2(int u, int to, int f) {
  if (u == 0) return ;
  id[u] = ++len;
  top[u] = to;
  pair<int, int> mx = make_pair(0, 0);
  for (int i = 0; i < G[u].size(); i++) {
    if (f == G[u][i]) continue;
    mx = max(mx, make_pair(sz[G[u][i]], G[u][i]));
  }
  dfs2(mx.second, to, u);
  for (int i = 0; i < G[u].size(); i++) {
    if (f == G[u][i] || mx.second == G[u][i]) continue;
    dfs2(G[u][i], G[u][i], u);
  }
}

void pushup(int rt) {
  t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

void pushdown(int rt, int l) {
  if (lazy[rt]) {
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    t[rt << 1] += lazy[rt] * ((l + 1) / 2);
    t[rt << 1 | 1] += lazy[rt]* (l - (l + 1) / 2);
    lazy[rt] = 0;
  }
}

void build(int rt, int left, int right) {
  if (left == right) {
    t[rt] = 0;
    return ;
  }
  build(lson), build(rson);
  pushup(rt);
}

ll query(int rt, int left, int right, int l, int r) {
  if (left == l && r == right) {
    return t[rt];
  }
  pushdown(rt, right - left + 1);
  if (mid >= r) return query(lson, l, r);
  else if (mid < l) return query(rson, l, r);
  else return query(lson, l, mid) + query(rson, mid + 1, r);
}

void add(int rt, int left, int right, int l, int r) {
  if (left == l && r == right) {
    lazy[rt]++;
    t[rt] += r - l + 1;
    return ;
  }
  pushdown(rt, right - left + 1);
  if (mid >= r) add(lson, l, r);
  else if (mid < l) add(rson, l, r);
  else add(lson, l, mid), add(rson, mid + 1, r);
  pushup(rt);
}

void init_HLD() {
  dfs1(1, -1, 1);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      if (fa[i - 1][j] == -1) fa[i][j] = -1;
      else fa[i][j] = fa[i - 1][fa[i - 1][j]];
    }
  }
  dfs2(1, 1, -1);
  build(1, 1, len);
}
