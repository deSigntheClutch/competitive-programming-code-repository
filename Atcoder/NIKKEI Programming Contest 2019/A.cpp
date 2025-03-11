#include <bits/stdc++.h>
using namespace std;

int main() {
      int n, a, b;
      cin >> n >> a >> b;

      cout << min(a, b) << " ";

      cout << ((a + b - n > 0) ? a + b - n : 0) << endl;
      return 0;
}