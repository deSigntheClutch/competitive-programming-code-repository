#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;

int guess(int v) {
      cout << "! " << v << endl;
      fflush(stdout);

      string res;
      cin >> res;

      if (res == ":)") {
            return 1;
      } else {
            return 0;
      }
}

int ask(int l, int r) {

}


int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n;

            int res = guess(1);

            if (res == 1) {
                  continue;
            }

            for (int i = 0; i < )
      }

      return 0;
}