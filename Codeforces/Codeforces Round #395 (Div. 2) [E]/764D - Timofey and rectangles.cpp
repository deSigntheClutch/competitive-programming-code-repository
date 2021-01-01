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

const int N = 6e5 + 10;

int n, x, y, a;
int main() {
  scanf("%d", &n);
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x, &y, &a, &a);
    printf("%d\n", 2 * (x & 1) + (y & 1) + 1);
  }
  return 0;
}
/*
int garx[2 * N], gary[2 * N], l1, l2, n;
int x1[N], y1[N], x2[N], y2[N], vis[N], ans[N];
vector<int> G[N];
vector<pair<int, int>> x[2 * N], y[2 * N];

void add(int u, int l, int r, int w, int type) {
  set<int> s;
  if (type == 0) {
    int lb = (int)(lower_bound(y[w].begin(), y[w].end(), mp(l, -100000000)) - y[w].begin());
    int rb = (int)(lower_bound(y[w].begin(), y[w].end(), mp(r, 100000000)) - y[w].begin());
    for (int i = lb; i < rb; i++) {
      if ((y[w][i].fi != l && y[w][i].fi != r) || (y[w][i].fi == l && y[w][i].se < 0) || (y[w][i].fi == r && y[w][i].se > 0))
        s.insert(abs(y[w][i].se));
    }
  } else {
    int lb = (int)(lower_bound(x[w].begin(), x[w].end(), mp(l, -100000000)) - x[w].begin());
    int rb = (int)(lower_bound(x[w].begin(), x[w].end(), mp(r, 100000000)) - x[w].begin());
    for (int i = lb; i < rb; i++) {
      if ((x[w][i].fi != l && x[w][i].fi != r)|| (x[w][i].fi == l && x[w][i].se < 0) || (x[w][i].fi == r && x[w][i].se > 0))
        s.insert(abs(x[w][i].se));
    }
  }
  for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
    if(*it == u) continue;
    G[u - 1].pb(*it - 1);
    G[*it - 1].pb(u - 1);
  }
}

void dfs(int u) {
  vis[u] = 1;
  set<int> s;
  for (int i = 0; i < G[u].size(); i++) {
    s.insert(ans[G[u][i]]);
  }
  for (int i = 1; ; i++) {
    if (s.find(i) == s.end()) {
      ans[u] = i;
      break;
    }
  }
  for (int i = 0; i < G[u].size(); i++) {
    if (!vis[G[u][i]]) {
      dfs(G[u][i]);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    garx[l1++] = x1[i];
    gary[l2++] = y1[i];
    garx[l1++] = x2[i];
    gary[l2++] = y2[i];
  }
  sort(garx, garx + l1);
  sort(gary, gary + l2);
  l1 = unique(garx, garx + l1) - garx;
  l2 = unique(gary, gary + l2) - gary;
  for (int i = 0; i < n; i++) {
    x1[i] = lower_bound(garx, garx + l1, x1[i]) - garx;
    x2[i] = lower_bound(garx, garx + l1, x2[i]) - garx;
    y1[i] = lower_bound(gary, gary + l2, y1[i]) - gary;
    y2[i] = lower_bound(gary, gary + l2, y2[i]) - gary;
  }
  for (int i = 0; i < n; i++) {
    x[x1[i]].pb(mp(y1[i], -(i + 1)));
    x[x1[i]].pb(mp(y2[i], (i + 1)));
    x[x2[i]].pb(mp(y1[i], -(i + 1)));
    x[x2[i]].pb(mp(y2[i], (i + 1)));
    y[y1[i]].pb(mp(x1[i], -(i + 1)));
    y[y1[i]].pb(mp(x2[i], i + 1));
    y[y2[i]].pb(mp(x1[i], -(i + 1)));
    y[y2[i]].pb(mp(x2[i], i + 1));
  }
  for (int i = 0; i < l1; i++) {
    sort(x[i].begin(), x[i].end());
  }
  for (int i = 0; i < l2; i++) {
    sort(y[i].begin(), y[i].end());
  }
  for (int i = 0; i < n; i++) {
    add(i + 1, x1[i], x2[i], y1[i], 0);
    add(i + 1, x1[i], x2[i], y2[i], 0);
    add(i + 1, y1[i], y2[i], x1[i], 1);
    add(i + 1, y1[i], y2[i], x2[i], 1);
  }
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    dfs(i);
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
*/
