#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 10;

bitset<N> can[30][N], answer[N];
char s[N][N], pattern[N][N];
int n, m, p, q;

void shift() {
  for (int c = 0; c < 30; c++) {
    for (int i = 0; i < n; i++) {
      bitset<N> tmp = (can[c][i] >> 1);
      tmp[m - 1] = tmp[m - 1] | (can[c][i][0] & 1);
      can[c][i] = tmp;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  cin >> p >> q;
  for (int i = 0; i < p; i++) {
    cin >> pattern[i];
  }
  for (int i = 0; i < n; i++) {
    answer[i].flip();
    for (int j = 0; j < m; j++) {
      can[(int)(s[i][j] - 'a')][i][j] = 1;
    }
  }
  for (int j = 0; j < q; j++) {
    for (int i = 0; i < p; i++) {
      if (pattern[i][j] == '?') continue;
      for (int k = 0; k < n; k++) {
        answer[(k - i + n) % n] &= can[pattern[i][j] - 'a'][k];
      }
    }
    shift();
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << answer[i][j];
    }
    cout << endl;
  }
  return 0;
}
