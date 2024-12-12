#include <iostream>
#include <queue>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;

int INF = 1e9 + 1;
const int N = 2e3 + 1;

int T;
int n, l;
pair<int, int> p[N];

int main() {
  cin >> T;
  while (T--) {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
      cin >> p[i].first >> p[i].second;
    }

    sort(p + 1, p + 1 + n, [](const pair<int, int>& a, const pair<int, int>& b) {
      if (a.second == b.second) {
        return a.first < b.first;
      }
      return a.second < b.second;
    });

    int ans = 0;

    for (int i = 1; i <= n; i++) {
      if (p[i].first <= l) {
        ans = 1;
      }
    }

    for (int r = 1; r <= n; r++) {
      long long sumQ = 0;
      int cntQ = 0;
      priority_queue<int, vector<int>, greater<int>> Q;
      for (int i = r - 1; i >= 1; i--) {
        Q.push(p[i].first);
        sumQ += p[i].first;
        cntQ += 1;

        long long cost = p[r].second - p[i].second + p[r].first;

        while (Q.size() > 0 && cost + sumQ > l) {
          int t = Q.top();
          //cout << t << endl;
          Q.pop();
          sumQ -= t;
          cntQ -= 1;
        }
        if (cost <= l) {
          ans = max(ans, 1 + cntQ);
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
