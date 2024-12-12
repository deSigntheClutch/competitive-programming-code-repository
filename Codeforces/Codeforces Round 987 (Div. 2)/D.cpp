#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const int N = 5e5 + 10;

int n, T;
int a[N], ans[N], dp[N], nxt[N];

int fa[N];

int find(int x) {
  if (fa[x] == x) return fa[x];
  return fa[x] = find(fa[x]);
}

void fa_merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (fa[u] != fa[v]) {
    fa[u] = v;
  }
}

void solve1() {
  // next i = rightmost j : a[j] < a[i]
  fill(nxt, nxt + 1 + n, 0);

  set<pair<int, int>> S;
  for (int i = 1; i <= n; i++) {
    S.insert(make_pair(a[i], i));
  }

  for (int i = n; i >= 1; i--) {
    if (nxt[i] != 0) continue;

    S.erase(make_pair(a[i], i));
    while(S.size() > 0 && S.rbegin()->first > a[i]) {
      nxt[S.rbegin()->second] = i;
      S.erase(*S.rbegin());
    }

    if (!nxt[i]) nxt[i] = i;
  }

  while(!S.empty()) S.erase(S.begin());

  for (int i = 1; i <= n; i++) {
    if (!S.empty()) {
      nxt[i] = max(nxt[i], nxt[S.begin()->second]);
    }

    S.insert(make_pair(-a[i], i));
  }

  dp[n] = *max_element(a + 1, a + n + 1);

  multiset<int> ms;
  for (int i = 1; i < n; i++) {
    ms.insert(a[i]);
  }

  for (int i = n - 1; i >= 1; i--) {
    ms.erase(a[i]);
    dp[i] = a[i];
    if (!ms.empty())
      dp[i] = max(*ms.rbegin(), dp[i]);

    dp[i] = max(dp[i], dp[nxt[i]]);
  }

  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;
}

void solve2() {
  for (int i = 1; i <= n; i++) {
    fa[i] = i;
    dp[i] = 0;
  }

  fill(nxt, nxt + 1 + n, 0);

  set<pair<int, int>> S;
  for (int i = 1; i <= n; i++) {
    S.insert(make_pair(a[i], i));
  }

  for (int i = n; i >= 1; i--) {
    S.erase(make_pair(a[i], i));
    while(!S.empty() && S.rbegin()->first > a[i]) {
      fa_merge(S.rbegin()->second, i);
      S.erase(*S.rbegin());
    }
  }

  while(!S.empty()) S.erase(S.begin());

  for (int i = 1; i <= n; i++) {
    if (!S.empty()) {
      if (a[i] < S.rbegin()->first)
        fa_merge(i, S.rbegin()->second);
    }

    S.insert(make_pair(a[i], i));
  }

  for (int i = 1; i <= n; i++) {
    int u = find(i);
    dp[u] = max(dp[u], a[i]);
  }

  for (int i = 1; i <= n; i++) {
    cout << dp[find(i)] << " ";
  }
  cout << endl;
}

int main() {
  cin >> T;
  for (int cs = 0; cs < T; cs++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    solve2();
  }
  return 0;
}
