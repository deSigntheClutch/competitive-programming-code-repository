#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 4;
const long long INF = 1e18 + 1;

int n, m;
long long k;
int T;



int main() {
      cin >> T;
      while (T--) {
            int x, y;
            cin >> n >> x >> y;

            int z = min(x, y);
            cout << (n + z - 1) / z << endl;
      }
      return 0;
}
