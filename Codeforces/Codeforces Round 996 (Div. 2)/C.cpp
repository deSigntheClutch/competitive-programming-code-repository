#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;

int n, m;
ll a[N][N];
ll sumr[N], sumc[N];
bool used[N][N];
string route;

void mark_a(int id, int x, int y) {
      if (id >= route.length()) {
            a[x][y] = 0 - sumr[x];
            return;
      }

      if (route[id] == 'D') {
            a[x][y] = 0 - sumr[x];
            sumr[x] = 0;
            sumc[y] += a[x][y];
            mark_a(id + 1, x + 1, y);
      } else {
            a[x][y] = 0 - sumc[y];
            sumc[y] = 0;
            sumr[x] += a[x][y];
            mark_a(id + 1, x, y + 1);
      }
}

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> m;
            cin >> route;
            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= m; j++) {
                        cin >> a[i][j];
                        used[i][j] = 0;
                  }
            }

            for (int i = 1; i <= n; i++) {
                  ll sum = 0;
                  for (int j = 1; j <= m; j++) {
                        sum += a[i][j];
                  }
                  sumr[i] = sum;
            }

            for (int i = 1; i <= m; i++) {
                  ll sum = 0;
                  for (int j = 1; j <= n; j++) {
                        sum += a[j][i];
                  }
                  sumc[i] = sum;
            }

            mark_a(0, 1, 1);

            for (int i = 1; i <= n; i++) {
                  for (int j = 1; j <= m; j++) {
                        cout << a[i][j] << " ";
                  }
                  cout << endl;
            }
      }

      return 0;
}