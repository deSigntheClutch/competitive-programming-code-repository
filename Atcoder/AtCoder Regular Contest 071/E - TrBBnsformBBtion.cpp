#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

string a, b;
int cnt[2][2][N];
int q;

int main() {
  ios::sync_with_stdio(false);
  cin >> a >> b;
  int n = a.length(), m = b.length();
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == 'A') cnt[0][0][i + 1]++;
    else cnt[0][1][i + 1]++;
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] == 'A') cnt[1][0][i + 1]++;
    else cnt[1][1][i + 1]++;
  }
  for(int i = 1; i <= n; i++) {
    cnt[0][0][i] += cnt[0][0][i - 1];
    cnt[0][1][i] += cnt[0][1][i - 1];
  }
   for(int i = 1; i <= m; i++) {
    cnt[1][0][i] += cnt[1][0][i - 1];
    cnt[1][1][i] += cnt[1][1][i - 1];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int c1 = 0, c2 = 0;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    c1 = 2 * (cnt[0][0][r1] - cnt[0][0][l1 - 1]) + cnt[0][1][r1] - cnt[0][1][l1 - 1];
    c2 = 2 * (cnt[1][0][r2] - cnt[1][0][l2 - 1]) + cnt[1][1][r2] - cnt[1][1][l2 - 1];
    if(c1 % 3 == c2 % 3) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

