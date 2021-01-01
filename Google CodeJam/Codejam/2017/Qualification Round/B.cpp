#include <bits/stdc++.h>
using namespace std;

const int N = 20 + 5;

long long n;
long long num[N], base[N];

void init() {
  long long tmp = 1;
  for (int i = 0; i < 18; i++) {
    base[i] = tmp;
    tmp *= 10;
  }
  long long t = n;
  memset(num, 0, sizeof num);
  for (int i = 0; i < 18; i++) {
    num[i] = t % 10;
    t /= 10;
  }
}

long long ones(int len, long long num) {
  if (len < 0) return 0;
  long long res = 0;
  for (int i = 0; i <= len; i++) {
    res += base[i] * num;
  }
  return res;
}

long long cal(long long u, int len) {
  if (len < 0) return 0;
  long long res = 0;
  long long cur = ones(len, num[len]);
  if (cur < u) {
    return base[len] * num[len] + cal(u - base[len] * num[len], len - 1);
  } else if (cur == u) {
    return cur;
  } else
    return base[len] * (num[len] - 1) + ones(len - 1, (long long)9);
}

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int T;
  cin >> T;
  for (int cs = 1; cs <= T; cs++) {
    cin >> n;
    if (n == (long long)1e18) n--;
    init();
    cout << "Case #" << cs << ": " << cal(n, 17) << endl;
  }
  return 0;
}

