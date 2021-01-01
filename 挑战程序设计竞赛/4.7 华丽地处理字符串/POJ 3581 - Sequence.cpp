#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int N = 200009;

int n, k, a[N], ra[N], sa[N], rnk[N], tmp[N];

bool cmp(int u, int v) {
  if(rnk[u] != rnk[v]) return rnk[u] < rnk[v];
  int tu = (u + k <= n ? rnk[u + k] : -1);
  int tv = (v + k <= n ? rnk[v + k] : -1);
  return tu < tv;
}

void init_sa() {
  for(int i = 0; i <= n; i++) {
    sa[i] = i;
    rnk[i] = i < n ? ra[i] : -1;
  }
  for(k = 1; k <= n; k <<= 1) {
    sort(sa, sa + n + 1, cmp);
    tmp[sa[0]] = 0;
    for(int i = 1; i <= n; i++) {
      tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
    }
    for(int i = 0; i <= n; i++) {
      rnk[i] = tmp[i];
    }
  }
}


int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + n);
  }
  for(int i = n - 1; i >= 0; i--) {
    ra[i] = a[n - i - 1];
  }
  init_sa();
  int ans = n - 1 - sa[1];
  return 0;
}
