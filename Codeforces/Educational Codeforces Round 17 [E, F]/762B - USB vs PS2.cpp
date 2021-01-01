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

const int N = 3e5 + 10;

priority_queue<int, vector<int>, greater<int>> usb, ps2, lef;
int a, b, c, m;

int main() {
  scanf("%d%d%d", &a, &b, &c);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    char no[10];
    int val;
    scanf("%d %s", &val, no);
    if (no[0] == 'P') {
      ps2.push(val);
    } else {
      usb.push(val);
    }
  }
  int cnt = 0;
  ll sum = 0;
  while (!usb.empty() && a) {
    sum += usb.top();
    usb.pop();
    cnt++, a--;
  }
  while (!usb.empty()) {
    lef.push(usb.top());
    usb.pop();
  }
  while (!ps2.empty() && b) {
    sum += ps2.top();
    ps2.pop();
    cnt++, b--;
  }
  while (!ps2.empty()) {
    lef.push(ps2.top());
    ps2.pop();
  }
  while (!lef.empty() && c) {
    c--;
    sum += lef.top();
    cnt++;
    lef.pop();
  }
  printf("%d %I64d\n", cnt, sum);
  return 0;
}

