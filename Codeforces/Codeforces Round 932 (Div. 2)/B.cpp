#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;
const int N = 2e5 + 19;

int T;
int n;
int a[N];
vector<int> pos[N];
int bound[N];

int get_mex(int l, int r) {
  set<int> s;
  for (int i = l; i <= r; i++) {
    s.insert(a[i]);
  }

  for (int res = 0; ; res++) {
    if (s.find(res) == s.end()) {
      return res;
    }
  }
}

int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) pos[i].clear();

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    int ans = get_mex(1, n);

    int cur_mex = 0;
    int break_point = -1;
    set<int> s;

    for (int i = 1; i <= n; i++) {
      s.insert(a[i]);
      while (s.find(cur_mex) != s.end()) {
        cur_mex += 1;
      }

      if (cur_mex == ans) {
        break_point = i;
        break;
      }
    }

    if (break_point == n || get_mex(break_point + 1, n) != ans) cout << -1 << endl;
    else {
      cout << 2 << endl;
      cout << 1 << " " << break_point << endl;
      cout << break_point + 1 << " " << n << endl;
    }
  }
  return 0;
}
