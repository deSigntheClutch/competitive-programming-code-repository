#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> C;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    C[a[i]]++;
  }
  int ans = 0;
  for (auto it = C.begin(); it != C.end(); it++) {
    if (it->first > it->second) ans += it->second;
    else if (it->first < it->second) ans += it->second - it->first;
  }
  cout << ans << endl;
  return 0;
}
