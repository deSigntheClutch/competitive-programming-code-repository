#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
const ll INF = 9e18 + 10;

ll a[N];
ll b, q, l;
int n;
map<ll, int> m;

int main() {
  scanf("%I64d %I64d %I64d %d", &b, &q, &l, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", a + i);
    m[a[i]] = 1;
  }
  ll ans = 0;
  if (q == 0) {
    if (m[0] != 1 && abs(b) <= l) {
      printf("inf\n");
    } else if (m[0] == 1 && (m[b] != 1 && abs(b) <= l)) {
      printf("1\n");
    } else {
      printf("0\n");
    }
  } else if (q == -1 || q == 1) {
    if (q == -1) {
      if (m[-b] != 1 && abs(b) <= l) ans++;
      if (m[b] != 1 && abs(b) <= l) ans++;
      if (ans >= 1) printf("inf\n");
      else printf("0\n");
    } else {
      if (m[b] != 1 && abs(b) <= l) ans++;
      if (ans >= 1) printf("inf\n");
      else printf("0\n");
    }
  } else {
    if (b == 0) {
      if (m[b] == 1) printf("0\n");
      else printf("inf\n");
    } else {
      vector<ll> v;
      v.push_back(b);
      while (INF / abs(b) >= abs(q)) {
        b *= q;
        v.push_back(b);
      }
      for (int i = 0; i < v.size(); i++) {
        if (m[v[i]] == 1 || abs(v[i]) > l) continue;
        else ans++;
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
