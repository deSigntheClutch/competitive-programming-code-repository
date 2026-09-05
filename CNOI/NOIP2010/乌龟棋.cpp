#include <bits/stdc++.h>
using namespace std;

typedef unsigned short us;

const int N = 351;
const int M = 41;
const int B = 5;

int n, m;
int a[N], f[5][M][M][M], cnt[5];

int main() {

      memset(f, -1, sizeof f);

      cin >> n >> m;

      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      for (int i = 1; i <= m; i++) {
            int t;
            cin >> t;
            cnt[t] += 1;
      }

      f[1][cnt[2]][cnt[3]][cnt[4]] = a[1];

      for (us i = 1; i <= n - 1; i++) {
            for (us c2 = 0; c2 <= cnt[2]; c2++) {
                  for (us c3 = 0; c3 <= cnt[3]; c3++) {
                        for (us c4 = 0; c4 <= cnt[4]; c4++) {
                              if (f[i % B][c2][c3][c4] != -1) {
                                    // 1
                                    us used1 = (i - 1) - (2 * (cnt[2] - c2) + 3 * (cnt[3] - c3) + 4 * (cnt[4] - c4));
                                    if (used1 < cnt[1]) {
                                          f[(i + 1) % B][c2][c3][c4] = max(f[(i + 1) % B][c2][c3][c4],
                                                                               f[i % B][c2][c3][c4] + a[i + 1]);
                                    }

                                    // 2 to 4
                                    for (us j = 2; j <= 4; j++) {
                                          if (j == 2 && c2 >= 1) {
                                                f[(i + 2) % B][c2 - 1][c3][c4] = max(f[(i + 2) % B][c2 - 1][c3][c4],
                                                                                     f[i % B][c2][c3][c4] + a[i + 2]);
                                          } else if (j == 3 && c3 >= 1) {
                                                f[(i + 3) % B][c2][c3 - 1][c4] = max(f[(i + 3) % B][c2][c3 - 1][c4],
                                                                                     f[i % B][c2][c3][c4] + a[i + 3]);
                                          } else if (j == 4 && c4 >= 1) {
                                                f[(i + 4) % B][c2][c3][c4 - 1] = max(f[(i + 4) % B][c2][c3][c4 - 1],
                                                                                     f[i % B][c2][c3][c4] + a[i + 4]);
                                          }
                                    }
                              }

                              f[i % B][c2][c3][c4] = -1;
                        }
                  }
            }
      }

      cout << f[n % B][0][0][0] << endl;

      return 0;
}
