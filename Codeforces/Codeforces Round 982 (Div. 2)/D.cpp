#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 4;
const int NN = 6e5 + 10;
const long long INF = 1e18 + 1;

int T, n, m, M;
int a[N], b[N];
long long sum[N];
long long f[NN];

long long nwmin(long long x, long long y) {
      return ((x > y) ? y : x);
}

int getMaxBound(int L, int R, long long val) {
      int l = L - 1, r = R, md;
      for (int i = 0; i < 22; i++) {
            md = (l + r) >> 1;
            if (sum[md] - sum[L - 1] <= val) l = md + 1;
            else r = md;
      }
      return (sum[md] - sum[L - 1] <= val) ? md : md - 1;
}

int main() {
      ios::sync_with_stdio(false);
      cin >> T;
      while (T--) {
            cin >> n >> m;
            M = m + 1;

            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  sum[i] = sum[i - 1] + a[i];
            }
            for (int i = 1; i <= m; i++) {
                  cin >> b[i];
            }

            for (int i = 0; i <= n; i++) {
                  int tmp = i*M;
                  for (int j = 0; j <= m; j++) {
                        f[tmp + j] = (i == 0) ? 0 : INF;
                  }
            }

            for (int i = 0; i < n; i++) {
                  int tmp = i*M;
                  for (int j = m - 1; j >= 1; j--) {
                        f[tmp + j] = nwmin(f[tmp + j], f[tmp + j + 1]);
                  }

                  for (int j = 1; j <= m; j++) {
                        int maxBound = getMaxBound(i + 1, n, b[m + 1 - j]);
                        int tmpM = maxBound * M;
                        if (maxBound > i) {
                              f[tmpM + j] = nwmin(f[tmpM + j], f[tmp + j] + j - 1);
                        }
                  }
            }

            long long ans = INF;
            int tmpNM = n*M;
            for (int j = 1; j <= m; j++) {
                  ans = nwmin(ans, f[tmpNM + j]);
            }
            cout << ((ans == INF) ? -1 : ans) << endl;
      }
      return 0;
}
