#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

bool matrix[N][N];
int n, q;

bool cal() {
  bool res = 0;
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      res ^= matrix[i][j] * matrix[j][i];
    }
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  vector<bool> ans;
  bool res = cal();
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1 || op == 2) {
      int num;
      scanf("%d", &num);
      res ^= 1;
    } else {
      ans.push_back(res);
    }
  }
  for(bool u: ans) printf("%d", u);
  printf("\n");
  return 0;
}

