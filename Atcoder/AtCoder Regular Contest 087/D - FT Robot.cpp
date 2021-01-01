#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 2;

int x, y, sum;
string order;
vector<int> a, b;
bool f[2][2 * N];

bool check(vector<int> x, int des) {
  memset(f, 0, sizeof f);
  int sz = (int)x.size();
  f[0][0] = true;
  sum = 0;
  for (int i = 0; i < sz; i++) {
    sum += x[i];
    int st = i & 1;
    memset(f[st ^ 1], 0, sizeof f[st ^ 1]);
    for (int j = 0; j <= 8000; j++) {
      if(j + x[i] <= 8000 && f[st][j] == true) f[st ^ 1][j + x[i]] = true;
      f[st ^ 1][j] |= f[st][j];
    }
  }
  for (int i = 0; i <= sum; i++) {
    if (f[sz & 1][i] == true && sum - 2 * i == des) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> order;
  cin >> x >> y;
  y = abs(y);
  int firstAdd = -1;
  int sLen = (int)order.length(), dir = 1;
  for (int i = 0; i < sLen; i++) {
    int pt = i;
    while (order[pt] != 'T' && pt < sLen) pt++;
    dir ^= 1;
    if (firstAdd == -1) {
      firstAdd = pt - i;
      i = pt;
      continue;
    }
    if (pt - i == 0) {
      continue;
    }
    if (dir == 0) a.push_back(pt - i); // hori
    else b.push_back(pt - i);
    i = pt;
  }
  x -= firstAdd; 
  x = abs(x);
  bool flag = true;
  flag &= check(a, x);
  flag &= check(b, y);
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
