#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 13;
const ll INF = 1e15 + 7;

int n, m;
ll f[N * N * N][N][N][N][N];
pair<int, pair<int, int>> a[N*N*N];

int main() {
      ios::sync_with_stdio(false);
      cin >> n;
      m = n * n * n;

      for (int i = 1; i <= n * n * n; i++) {
            cin >> a[i].first >> a[i].second.first >> a[i].second.second;
      }

      sort(a + 1, a + m + 1);

      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  for (int k = 1; k <= n; k++) {
                        for (int l = 1; l <= n; l++) {
                              f[0][i][j][k][l] = INF;
                        }
                  }
            }
      }

      for (int i = 1; i <= m; i++) {
            int v0 = a[i].first, v1 = a[i].second.first, v2 = a[i].second.second;

            for (int j = 1; j <= n; j++) {
                  for (int k = j + 1; k <= n; k++) {
                        for (int l = 1; l <= n; l++) {
                              for (int p = l + 1; p <= n; p++) {
                                    if (j != v1 && k != v1 && l != v2 && p != v2) {
                                          f[i][j][k][l][p] = min(f[i][j][k][l][p], (ll)v0 + v1 + v2);
                                    }
                              }
                        }
                  }
            }
      }

      ll ans = INF;

      for (int i = 1; i <= m; i++) {
            for (int j = 1; j < i; j++) {
                  if (a[i].first == a[j].first) break;

                  if (a[i].second.first != a[j].second.first && a[j].second.second != a[i].second.second) {
                        int v0 = a[i].second.first, v1 = a[j].second.first;
                        int w0 = a[i].second.second, w1 = a[j].second.second;
                        if (v0 > v1) swap(v0, v1);
                        if (w0 > w1) swap(w0, w1);

                        int k = j;
                        while (k >= 1 && a[i].first == a[j].first) k--;
                        ans = min(f[k][v0][v1])
                  }
            }
      }
      return 0;
}
