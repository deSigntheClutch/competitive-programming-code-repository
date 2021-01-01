#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
 
string s;
int a[N], sum[N], f[N], q[N];
int n, k, Q, l, r, T;
 
int solve() {
  int res = 0;
  l = r = 0;
  q[r++] = 0;
  for (int i = 1; i <= n; i++) {
    while (r > l && sum[i] - sum[q[l]] > k) l++;
    res = max(res, min(T, f[i] - f[q[l]] + k));
    while (r > l && f[i] <= f[q[r - 1]]) r--;
    q[r++] = i;
  }
  return res;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  n = s.length();
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + (int)(s[i - 1] - '0');
    f[i] = i - 2 * sum[i];
  }
  T = n - sum[n];
  cin >> Q;
  while (Q--) {
    cin >> k;
    cout << solve() << endl;
  }
  return 0;
}