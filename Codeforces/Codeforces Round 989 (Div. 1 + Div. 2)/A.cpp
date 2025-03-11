#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

vector<int> G[N];
int a, b;


int main() {
      int T;
      cin >> T;
      while (T--) {
            cin >> a >> b;
            if (a > b) swap(a, b);
            for (int i=a; ;i++) {
                  if (i % a == i % b) {
                        cout << i << endl;
                        break;
                  }
            }
      }
      return 0;
}
