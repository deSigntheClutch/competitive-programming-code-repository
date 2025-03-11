#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 4;
const long long INF = 1e10 + 1;

int T, n, q;
int a[N];
vector<long long> v;

int main() {
      cin >> T;
      while (T--) {
            map<int, int> cnt;
            cnt.clear();
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  cnt[a[i]] += 1;
            }

            int ans = 0;
            int nSingleColor = 0;
            for (int i = 1; i <= n; i++) {
                  if (cnt[i] == 0) continue;
                  else if (cnt[i] == 1) {
                        nSingleColor += 1;
                  } else {
                        ans += 1;
                  }
            }

            cout << ans + 2 * ((nSingleColor + 1) / 2) << endl;
      }
}
