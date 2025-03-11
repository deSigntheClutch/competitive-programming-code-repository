#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];

int main() {
      cin >> n;
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] -= i;
      }

      long long s = 0;
      sort(a + 1, a + 1 + n);

      for (int i = 1; i <= n; i++) {
            s += abs(a[i] - a[(n + 1)/ 2]);
      }
      cout << s << endl;
      return 0;
}