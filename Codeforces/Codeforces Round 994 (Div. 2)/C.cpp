#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e10 + 1;

int n, x, y;
int T;
int a[N];

int getMex(int u, int v) {
      multiset<int> ss;
      ss.insert(u);
      ss.insert(v);

      int res = 0;
      while (true) {
            if (ss.find(res) == ss.end()) {
                  return res;
            }
            res += 1;
      }
}

int main() {
      cin >> T;
      while (T--) {
            cin >> n >> x >> y;
            x--, y--;

            if (n & 1) {
                  a[x] = 0;
                  int cur = 1;
                  for (int i = (x + 1) % n; i != y; i = (i + 1) % n) {
                        a[i] = cur;
                        cur ^= 1;
                  }

                  if (cur == a[x]) {
                        a[y] = 2;
                        cur = 0;
                  } else {
                        a[y] = 1;
                        cur ^= 1;
                  }

                  for (int i = (y + 1) % n; i != x; i = (i + 1) % n) {

                        if ((i + 1) % n == x) {
                              a[i] = getMex(a[x], a[(i - 1 + n) % n]);
                              continue;
                        }
                        a[i] = cur;
                        cur ^= 1;
                  }
            } else {
                  a[x] = 0;
                  int cur = 1;
                  for (int i = (x + 1) % n; i != x; i = (i + 1) % n) {
                        a[i] = cur;
                        cur ^= 1;
                  }

                  if (a[y] == a[x]) {
                        a[y] = 2;
                  }
            }
            for (int i = 0; i < n; i++) {
                  cout << a[i] << " ";
            }
            cout << endl;

      }
}
