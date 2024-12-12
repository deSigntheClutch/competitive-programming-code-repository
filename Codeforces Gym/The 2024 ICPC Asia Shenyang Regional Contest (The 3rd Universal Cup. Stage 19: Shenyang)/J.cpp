#include <iostream>

using namespace std;

string s[8][8];
int strength[8][8];

// 6:50 12-1 2024
int main() {

  for (int i = 0; i < 8; i++) {
    cin >> s[0][i] >> strength[0][i];
  }
  int m = 8;
  for (int round = 0; round < 3; round++) {

    for (int i = 0; i < m; i += 2) {
      if (strength[round][i] > strength[round][i + 1]) {
        strength[round + 1][i / 2] = strength[round][i];
        s[round + 1][i / 2] = s[round][i];
      } else {
        strength[round + 1][i / 2] = strength[round][i + 1];
        s[round + 1][i / 2] = s[round][i + 1];
      }
    }
    m /= 2;
  }

  if (strength[2][0] > strength[2][1]) {
    cout << s[2][0] << " beats " << s[2][1] << endl;
  } else {
    cout << s[2][1] << " beats " << s[2][0] << endl;
  }
  return 0;
}
