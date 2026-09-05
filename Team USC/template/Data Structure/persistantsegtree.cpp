 
struct Tree {
  int l, r, lth;
  int lz, rz, mz, v;
} t[N * LOG_N];
 
int n, m, gr[N], rt[N], len, nu;
 
void push_up(int rt) {
  if (t[t[rt].l].lz == t[t[rt].l].lth) {
    t[rt].lz = t[t[rt].l].lz + t[t[rt].r].lz;
  } else {
    t[rt].lz = t[t[rt].l].lz;
  }
  if (t[t[rt].r].rz == t[t[rt].r].lth) {
    t[rt].rz = t[t[rt].l].rz + t[t[rt].r].rz;
  } else {
    t[rt].rz = t[t[rt].r].rz;
  }
  t[rt].mz = max(t[t[rt].l].mz, max(t[t[rt].r].mz, t[t[rt].l].rz + t[t[rt].r].lz));
  t[rt].v = max(t[rt].lz, max(t[rt].rz, t[rt].mz));
}
 
int Insert(int rt, int left, int right, int id) {
  int tp = ++nu;
  t[tp] = t[rt];
  t[tp].lth = right - left + 1;
  if (left != right) {
    if (id <= mid) t[tp].l = Insert(t[rt].l, left, mid, id);
    else t[tp].r = Insert(t[rt].r, mid + 1, right, id);
    push_up(tp);
  } else {
    t[tp].lz = t[tp].mz = t[tp].rz = t[tp].v = 1;
  }
  return tp;
}
 
Tree Query(int rt, int left, int right, int l, int r) {
  /*printf("%d %d %d %d %d\n", rt, left, right, l, r);
    printf("%d: %d %d\n", rt, t[rt].l, t[rt].r);
    printf("%d %d %d %d\n\n", t[rt].lz, t[rt].mz, t[rt].rz, t[rt].v);
  */
  if (left == l && r == right) {
    return t[rt];
  }
  if (mid >= r) {
    return Query(t[rt].l, left, mid, l, r);
  } else if (mid < l) {
    return Query(t[rt].r, mid + 1, right, l, r);
  } else {
    Tree t1 = Query(t[rt].l, left, mid, l, mid), t2 = Query(t[rt].r, mid + 1, right, mid + 1, r);
    Tree res;
    res.lth = t1.lth + t2.lth;
    if (t1.lz == t1.lth) res.lz = t1.lz + t2.lz;
    else res.lz = t1.lz;
    if (t2.rz == t2.lth) res.rz = t2.rz + t1.rz;
    else res.rz = t2.rz;
    res.mz = max(t1.mz, max(t2.mz, t1.rz + t2.lz));
    res.v = max(res.lz, max(res.rz, res.mz));
    return res;
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> gr[i];
    fence[i + 1] = mp(gr[i], i + 1);
  }
  sort(gr, gr + n);
  len = unique(gr, gr + n) - gr;
  for (int i = 1; i <= n; i++) {
    fence[i].fi = lower_bound(gr, gr + len, fence[i].fi) - gr + 1;
  }
  sort(fence + 1, fence + 1 + n, greater<pair<int, int> >());
  //printf("%d\n", len);
  t[0].lth = 1;
  for (int i = 1; i <= n; i++) {
    //printf("%d\n", fence[i].se);
    rt[i] = Insert(rt[i - 1], 1, n, fence[i].se);
    //  printf("%d\n", rt[i]);
  }
  /*
  for(int i = 0; i <= nu; i++) {
    printf("%d: %d %d\n", i, t[i].l, t[i].r);
    printf("%d %d %d %d\n\n", t[i].lz, t[i].mz, t[i].rz, t[i].v);
  }*/
  //printf("%d\n", Query(rt[3], 1, n, 2, 5).v);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    int l = 1, r = n, md;
    for (int cs = 0; cs < 22; cs++) {
      md = (l + r) >> 1;
      int tmp = Query(rt[md], 1, n, a, b).v;
      //printf("%d : %d %d  %d %d\n", i, a, b, md,tmp);
      if (tmp < c) l = md + 1;
      else r = md;
    }
    //cout << md << endl;
    //cout << fence[md - 1].fi - 1 << endl;
    cout << gr[fence[md].fi - 1] << endl;
  }
  return 0;
}
 