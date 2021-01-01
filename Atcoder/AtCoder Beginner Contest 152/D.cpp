#include <bits/stdc++.h>
using namespace std;
#define mid ((left + right) >> 1)
#define lson rt << 1, left, mid
#define rson rt << 1 | 1, mid + 1, right

const double pi = acos(-1.0);
const int INF = 1e9 + 1;
const int N = 1e5 + 5;

int n;
int sum[11][11];

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int val = i;
    int head = -1;
    while (val >= 10) val /= 10;
    head = val;
    int tail = i % 10;
    sum[head][tail] += 1;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int val = i;
    int head = -1;
    while (val >= 10) val /= 10;
    head = val;
    int tail = i % 10;
    if (tail == 0) continue;
    ans += sum[tail][head];
  }
  cout << ans << endl;
  return 0;
}
