#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

int n, m;
long long k;
int T;
long long a[N][N];
long long f[N][N][N], g[N][N];


int main() {
      cin >> T;
      while (T--) {
            cin >> n >> m >> k;

            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        cin >> a[i][j];
                  }
            }

            for (int i = 0; i <= n; i++) {
                  for (int j = 0; j <= m; j++) {
                        g[i][j] = INF;
                        for (int p = 0; p <= m; p++) {
                              f[i][j][p] = INF;
                        }
                  }
            }

            for (int i = 0; i < m; i++) {
                  f[0][0][i] = a[0][i % m] + k * i;
            }

            for (int i = 0; i < n; i++) {
                  for (int j = 0; j < m; j++) {
                        for (int v = 0; v < m; v++) {
                              if (i > 0) f[i][j][v] = min(f[i][j][v], g[i - 1][j] + a[i][(v + j) % m] + k * v);
                        }
                  }

                  for (int v = 0; v < m; v++) {
                        for (int j = 1; j < m; j++) {
                              f[i][j][v] = min(f[i][j][v], f[i][j - 1][v] + a[i][(v + j) % m]);
                        }
                  }

                  for (int j = 0; j < m; j++) {
                        for (int v = 0; v < m; v++) {
                              g[i][j] = min(g[i][j], f[i][j][v]);
                        }
                  }
            }

            cout << g[n - 1][m - 1] << endl;
      }
      return 0;
}
