#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 2e5 + 4;
const int INF = 1e9 + 10;

int T, n, q;
vector<int> pos[16];
int status[N];

int cal(int l, int r, int msk) {
  int res = INF;
  int ptr = lower_bound(pos[msk].begin(), pos[msk].end(), r) - pos[msk].begin();

  for (int i = 0; i < 3; i++) {
    int newptr = ptr - i;
    if (newptr < 0) break;
    if (newptr < pos[msk].size()) {
      res = min(res, abs(pos[msk][newptr] - r) + abs(pos[msk][newptr] - l));
    }
  }
  return res;
}


int main() {
  cin >> T;
  while (T--) {
    cin >> n >> q;

    for (int i = 0; i < 16; i++) pos[i].clear();

    for (int i = 1; i <= n; i++) {
      string s;
      int msk = 0;
      cin >> s;
      if (s[0] == 'R') msk |= 1;
      else if (s[0] == 'G') msk |= 2;
      else if (s[0] == 'B') msk |= 4;
      else msk |= 8;

      if (s[1] == 'R') msk |= 1;
      else if (s[1] == 'G') msk |= 2;
      else if (s[1] == 'B') msk |= 4;
      else msk |= 8;

      status[i] = msk;
      pos[msk].push_back(i);
    }
    for (int i = 0; i < q; i++) {
      int l, r;
      cin >> l >> r;
      if ((status[l] & status[r]) == 0) {

        int ans = INF;
        for (int msk = 0; msk < 16; msk++) {
          if (__builtin_popcount(msk) == 2 && (msk & status[l]) && (msk & status[r])) {
            ans = min(ans, cal(l, r, msk));
          }
        }
        if (ans == INF) cout << -1 << endl;
        else cout << ans << endl;
      } else {
        cout << abs(r - l) << endl;
      }
    }
  }
  return 0;
}
