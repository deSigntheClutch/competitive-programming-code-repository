#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 4;

int T, n;
long long a[N], b[N];
bool used[N];
vector<int> G[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n;

    vector<long long> val;
    for (int i = 0; i < n; i++) {
      G[i].clear();
      used[i] = false;
    }

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i] + i;
      val.push_back(b[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());

    for (int i = 1; i <= n; i++) {
      int pos = lower_bound(val.begin(), val.end(), b[i]) - val.begin();
      G[pos].push_back(i);
    }

    long long ans = n + 1;
    queue<long long> Q;
    int id = lower_bound(val.begin(), val.end(), n + 1) - val.begin();
    if (id < val.size() && val[id] == n + 1) {
      used[id] = true;
      Q.push(n + 1);
    }

    while (!Q.empty()) {
      long long curLen = Q.front();
      ans = max(ans, curLen);
      Q.pop();
      int idx = lower_bound(val.begin(), val.end(), curLen) - val.begin();

      if (idx < val.size() && val[idx] == curLen) {
        for (int x : G[idx]) {
          if (x == 1) continue;
          ans = max(ans, curLen + x - 1);
          int idy = lower_bound(val.begin(), val.end(), curLen + x - 1) - val.begin();
          if (idy < val.size() && val[idy] == curLen + x - 1) {
            if(!used[idy]) {
              used[idy] = true;
              Q.push(curLen + x - 1);
            }
          }
        }
      }
    }
    cout << ans - 1 << endl;
  }
  return 0;
}
