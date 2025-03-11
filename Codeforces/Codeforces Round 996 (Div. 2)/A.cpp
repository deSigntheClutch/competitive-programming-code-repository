#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, a, b;


int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n >> a >> b;

            if (abs(a - b) % 2 == 0) {
                  cout << "yes" << endl;

            } else {
                  cout << "no" << endl;
            }
      }

      return 0;
}