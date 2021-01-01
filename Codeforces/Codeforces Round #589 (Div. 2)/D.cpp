#ifdef LOCAL
#include "message.h"
#define DEBUG true
#else
#include <message.h>
#define DEBUG false
#endif
#include "sandwich.h"
#include <bits/stdc++.h>
#define LL long long
using namespace std;
int n, nodes, me;

LL a[5123456];
LL xs[130], sums[130], prefixes[130], suffixes[130];
struct ret {
  LL x, prefix, suffix, sum;
};
ret recur(int l, int r) {
  if (l == r - 1) {
    return {xs[l], prefixes[l], suffixes[l], sums[l]};
  }
  int mid = (l + r) / 2;
  ret p = recur(l, mid), q = recur(mid, r);
  return {
    max(max(p.x, q.x), p.suffix + q.prefix),
    max(p.prefix, q.prefix + p.sum),
    max(q.suffix, p.suffix + q.sum),
    p.sum + q.sum
  };
}
void master() {
  long long total = 0;
  for (int i = 0; i < nodes - 1; i++) {
    Receive(i);
    xs[i] = GetLL(i);
    sums[i] = GetLL(i);
    total += sums[i];
    prefixes[i] = GetLL(i);
    suffixes[i] = GetLL(i);
  }
  ret r = recur(0, 128);
  printf("%lld\n", - total + r.x);
}
void slave(int l, int r) {
  if (DEBUG) printf("%d %d\n", l, r);
  long long x = 0, y = 0;
  long long sum = 0;
  long long prefix = 0;
  for (int i = l; i < r; i++) {
    int k = -GetTaste(i);
    y = max(0LL, y + k);
    x = max(x, y);
    sum += k;
    a[i - l] = sum;
    prefix = max(prefix, sum);
  }
  long long suffix = sum;
  for (int i = l; i < r; i++) {
    suffix = max(suffix, sum - a[i - l]);
  }
  if (DEBUG) printf("%lld %lld %lld %lld\n", x, prefix, suffix, sum);
  PutLL(nodes - 1, x);
  PutLL(nodes - 1, sum);
  PutLL(nodes - 1, prefix);
  PutLL(nodes - 1, suffix);
  Send(nodes - 1);
}
int main() {
  n = GetN();
  nodes = NumberOfNodes();
  me = MyNodeId();
  if (me == NumberOfNodes() - 1) {
    master();
  } else {
    int l = 1LL * n * me / (nodes-1);
    int r = 1LL * n * (me + 1) / (nodes-1);
    slave(l, r);
  }
  return 0;
}
