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

const int N = 1e5 + 10;

bool flag;
int n, cnt, m, vis[N], col[N];
vector<int> G[N];
vector<int> comp;

void dfs(int u, int c) {
  vis[u] = 1;
  cnt++;
  col[u] = c;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (!vis[v]) {
      dfs(v, c ^ 1);
    } else {
      if (c ^ 1 != col[v]) {
        flag = false;
      }
    }
  }
}

int main() {
  memset(col, -1, sizeof col);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cnt = 0;
    flag = true;
    dfs(i, 1);
    if (cnt != 1) {
      if (flag) ans += 2;
      else ans += 1;
    }
    if(flag == true) comp.push_back(cnt);
    else comp.push_back(-cnt);
  }
  int mul_one = 0;
  int mul_1 = 0, mul_2 = 0;
  for (int i = 0; i < comp.size(); i++) {
    if (comp[i] == 1) {
      ans += (long long)2 * (n - 1) + 1 - mul_one * 2;
      mul_one++;
    } else {
      if(comp[i] > 0) mul_2++;
      else mul_1++;
    }
  }
  ans += (long long) mul_1 * (mul_1 - 1);
  ans += (long long) mul_2 * mul_1 * 2;
  ans += (long long) mul_2 * (mul_2 - 1)* 2;
  printf("%lld\n", ans);
  return 0;
}

