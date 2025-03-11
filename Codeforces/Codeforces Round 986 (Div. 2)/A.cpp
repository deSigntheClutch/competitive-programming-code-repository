#include <bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;

int n, a, b;
string s;

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> a >> b;
            cin >> s;
            bool flag = false;
            int x = 0, y = 0;
            for (int i = 0; i < n*N; i++) {
                  if (x == a && y == b) {
                        flag = true;
                        break;
                  }
                  if (s[i%n] == 'E') {
                        x += 1;
                  } else if (s[i%n] == 'W') {
                        x -= 1;
                  } else if (s[i%n] == 'S') {
                        y -= 1;
                  } else if (s[i%n] == 'N') {
                        y += 1;
                  }
            }

            cout << ((flag) ? "yes" : "no") << endl;
      }
      return 0;
}