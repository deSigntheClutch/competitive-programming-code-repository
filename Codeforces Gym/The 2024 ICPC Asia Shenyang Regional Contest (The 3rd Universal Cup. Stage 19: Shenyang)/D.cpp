#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int T, n;
int a[N], b[N], p[N];
bool fwt[N];

void add(int x) {
      while (x <= n) {
            fwt[x] ^= 1;
            x += x & -x;
      }
}

bool get(int x) {
      bool res = 0;
      while(x) {
            res ^= fwt[x];
            x -= x & -x;
      }
      return res;
}

int main() {
      ios::sync_with_stdio(false);
      cin >> T;
      while (T--) {
            cin >> n;

            fill(fwt, fwt + n + 1, 0);

            for (int i = 1; i <= n; i++) cin >> a[i];
            for (int i = 1; i <= n; i++) cin >> b[i];
            for (int i = 1; i <= n; i++) {
                  p[a[i]] = b[i];
            }

            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                  cnt ^= get(p[i] - 1);
                  add(p[i]);
            }

            cnt = ((long long) n * (n - 1) / 2) & 1 ^ cnt;
            string ans = (cnt == 1) ? "A" : "B";

            for (int q = 0; q < n - 1; q++) {
                  string s;
                  int l, r, d;
                  cin >> s >> l >> r >> d;

                  if (((long long)(r - l) * d) & 1) {
                        cnt ^= 1;
                  }
                  ans += (cnt == 1) ? "A" : "B";
            }

            cout << ans << endl;
      }
      return 0;
}
