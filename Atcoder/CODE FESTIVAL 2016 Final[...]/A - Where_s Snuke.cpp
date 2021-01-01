#include <bits/stdc++.h>
using namespace std;

const int N = 30;

int h, w;
string s[N][N];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(s[i][j] == "snuke") {
        cout << (char)('A' + j) << i + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
