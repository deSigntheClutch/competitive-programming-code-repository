#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
const int B = 500;

vector<int> bucket[N];
int n, Q;
int a[N], fwt[N];
long long ans = 0;

void change(int id, int v1, int v2) {
  int b = id / B;
  for (int i = 0; i < bucket[b].size(); i++) {
    if (bucket[b][i] == v1) {
      bucket[b][i] = v2;
      break;
    }
  }
  sort(bucket[b].begin(), bucket[b].end());
  a[id] = v2;
}

int query(int x) {
  int res = 0, pt = 0;
  while (pt / B != x / B) {
    res += bucket[pt / B].size() - (int)(lower_bound(bucket[pt / B].begin(), bucket[pt / B].end(), a[x]) - bucket[pt / B].begin());
    pt += B;
  }
  while (pt != x) {
    res += (a[pt] > a[x]);
    pt++;
  }
  if (x + 1 >= n) return res;
  pt = x + 1;
  while (pt % B != 0 && pt < n) {
    res += (a[pt] < a[x]);
    pt++;
  }
  while (pt / B != (n - 1) / B && pt < n) {
    res += (int)(lower_bound(bucket[pt / B].begin(), bucket[pt / B].end(), a[x]) - bucket[pt / B].begin());
    pt += B;
  }
  while (pt != x && pt < n) {
    res += (a[pt] < a[x]);
    pt++;
  }
  return res;
}

void update(int l, int r) {
  if (a[l] > a[r]) ans++;
  ans -= query(l);
  ans -= query(r);
  int u = a[l], v = a[r];
  swap(a[l], a[r]);
  change(l, u, v);
  change(r, v, u);
  ans += query(l);
  ans += query(r);
  if (a[l] > a[r]) ans--;
}

int main() {
  scanf("%d %d", &n, &Q);
  for (int i = 0; i < n; i++) {
    a[i] = i + 1;
  }
  int C = (n - 1) / B + 1;
  for (int i = 0; i < n; i++) {
    bucket[i / B].push_back(a[i]);
  }
  for (int i = 0; i < C; i++) {
    sort(bucket[i].begin(), bucket[i].end());
  }
  for (int i = 0; i < Q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (l > r) swap(l, r);
    update(l - 1, r - 1);
    printf("%I64d\n", ans);
  }
  return 0;
}
/*

6 7
1 4
3 5
2 3
3 3
3 6
2 1
5 1

*/
