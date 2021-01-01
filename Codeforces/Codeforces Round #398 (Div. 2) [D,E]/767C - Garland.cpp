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

const int N = 1e6 + 10;

int a[N], sum[N], f[N], sz[N], fat[N];
int tar, fst = -1, snd = -1, root;
vector<int> G[N];
int n;

void dfs1(int u, int fa) {
  fat[u] = fa;
  sum[u] = a[u];
  sz[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    sum[u] += sum[v];
    sz[u] += sz[v];
  }
}

void dfs2(int u, int fa) {
  if (sum[u] == tar) f[u] = u;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs2(v, u);
    if(f[u] == 0) f[u] = f[v];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    a[i] = v;
    if (u == 0) {
      root = i;
      continue;
    }
    G[i].pb(u), G[u].pb(i);
  }
  dfs1(root, -1);
  if (sum[root] % 3 == 0) {
    tar = sum[root] / 3;
    dfs2(root, -1);
    for (int i = 1; i <= n; i++) {
      int cnt = 0;
      for (int j = 0; j < G[i].size(); j++) {
        int v = G[i][j];
        if (v == fat[i]) continue;
        cnt += (f[v] > 0);
        if (cnt == 1 && f[v] > 0) {
          fst = f[v];
        } else if (cnt == 2 && f[v] > 0) {
          snd = f[v];
        }
      }
      if (cnt < 2) {
        fst = snd = -1;
        continue;
      } else {
        break;
      }
    }
    if (fst == -1) {
      for (int i = 1; i <= n; i++) {
        if (sum[i] != tar * 2 || root == i) continue;
        for (int j = 0; j < G[i].size(); j++) {
          int v = G[i][j];
          if (v == fat[i]) continue;
          if (f[v] > 0) {
            fst = f[v], snd = i;
            break;
          }
        }
      }
    }
  }
  if (fst == -1) {
    printf("-1\n");
  } else {
    printf("%d %d\n", fst, snd);
  }
  return 0;
}

