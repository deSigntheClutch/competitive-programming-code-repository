#include <bits/stdc++.h>

using namespace std;

const int N = 1E3 + 10;
const long long INF = 1E18 + 10;
const int K = 3E5 + 10;

char ch[N][N];
int n, m, k;
long long pref[N][N], pre[26][N][N], fre[26][N][N];
int x1[K], x2[K], y1[K], y2[K];
char c[K][3];

long long cal(int u, int v) {
  int id = ch[u][v] - 'a';
  long long res = 0;
  for (int i = 0; i < 26; i++) {
    if (i < id) res += (long long)(id - i) * (fre[i][u][v]);
    else res += (long long)(i - id) * (fre[i][u][v]);
  }
  return res;
}

long long query(int u) {
  int id = c[u][0] - 'a';
  long long res = pref[n][m] - (pref[x2[u]][y2[u]] - pref[x2[u]][y1[u] - 1] - pref[x1[u] - 1][y2[u]] + pref[x1[u] - 1][y1[u] - 1]);
  for (int i = 0; i < 26; i++) {
    if (i < id) res += (long long)(id - i) * (pre[i][x2[u]][y2[u]] - pre[i][x2[u]][y1[u] - 1] - pre[i][x1[u] - 1][y2[u]] + pre[i][x1[u] - 1][y1[u] - 1]);
    else res += (long long)(i - id) * (pre[i][x2[u]][y2[u]] - pre[i][x2[u]][y1[u] - 1] - pre[i][x1[u] - 1][y2[u]] + pre[i][x1[u] - 1][y1[u] - 1]);
  }
  return res;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch[i] + 1);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d%d%d%d %s", &x1[i], &y1[i], &x2[i], &y2[i], c[i]);
    fre[c[i][0] - 'a'][x1[i]][y1[i]]++;
    fre[c[i][0] - 'a'][x1[i]][y2[i] + 1]--;
    fre[c[i][0] - 'a'][x2[i] + 1][y1[i]]--;
    fre[c[i][0] - 'a'][x2[i] + 1][y2[i] + 1]++;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j <= n; j++) {
      for (int v = 1; v <= m; v++) {
        fre[i][j][v] += fre[i][j][v - 1];
      }
    }
    for (int j = 1; j <= m; j++) {
      for (int v = 1; v <= n; v++) {
        fre[i][v][j] += fre[i][v - 1][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int id = ch[i][j] - 'a';
      int cnt = 0;
      for (int c = 0; c < 26; c++) {
        if (id != c) cnt += fre[c][i][j];
      }
      fre[id][i][j] = k - cnt;
    }
  }
  for (int v = 0; v < 26; v++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        pre[v][i][j] = pre[v][i][j - 1] + pre[v][i - 1][j] - pre[v][i - 1][j - 1] + fre[v][i][j];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1] + cal(i, j);
    }
  }
  long long ans = INF;
  for (int i = 1; i <= k; i++) {
    ans = min(ans, query(i));
  }
  printf("%I64d\n", ans);
  return 0;
}

