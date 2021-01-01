#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1e6 + 10;
const int F = 1e7 + 10;

long long sum[F];
int n, m, k;
int a[N], b[N];
pair<int, int> p[N];

bool check(int u) {
  memset(sum, 0, sizeof sum);
  for(int i = 1; i <= n; i++) {
    sum[a[i]]++;
  }
  for(int i = 1; i <= m; i++) {
    sum[b[i]]++;
  }
  for(int i = 0; i< F; i++) {
    if(i >= 1) {
        sum[i] += sum[i - 1];
    }
    if(sum[i] > (long long)(i + 1) * k) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  int l = 0, r = m, md;
  for(int i = 0; i < 30; i++) {
    md = (l + r) >> 1;
    if(check(md)) l = md + 1;
    else r = md;
  }
  printf("%I64d\n", md);
  return 0;
}

