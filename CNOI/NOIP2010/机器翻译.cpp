#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
const int M = 1e2 + 3;

int n, m;
deque<int> memo;
map<int, int> in_memo;

int main() {

      cin >> m >> n;

      int ans = 0;
      for (int i = 1; i <= n; i++) {
            int w;
            cin >> w;

            if (!in_memo[w]) {
                  if (memo.size() == m) {
                        int kicked = memo.front();
                        memo.pop_front();
                        in_memo[kicked] = 0;

                        memo.push_back(w);
                        in_memo[w] = 1;
                  } else {
                        memo.push_back(w);
                        in_memo[w] = 1;
                  }

                  ans += 1;
            }
      }

      cout << ans << endl;
      return 0;
}
