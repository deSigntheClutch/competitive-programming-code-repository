#include <bits/stdc++.h>
using namespace std;

const int N = 501;

int n;
int g[N][N];

void solve(int l, int r, int idx) {
      if (r == l) return ;

      int mid = l + r >> 1;

      for (int i = l; i <= mid; i++) {
            for (int j = mid + 1; j <= r; j++) {
                  g[i][j] = g[j][i] = idx;
            }
      }

      solve(l, mid, idx + 1);
      solve(mid + 1, r, idx + 1);
}


int main() {
      cin >> n;
      solve(1, n, 1);

      for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                  cout << g[i][j] << " ";
            }
            cout << endl;
      }
      return 0;
}