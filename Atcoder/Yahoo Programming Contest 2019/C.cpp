#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
	cin >> n >> a >> b;
  	if (a + 2 >= b) cout << n + 1 << endl;
  	else {
      	if (n <= a - 1) cout << n + 1 << endl;
      	else {
          if ((n - a) % 2 == 0) cout << (long long)(n + 1 - a) / 2 * (b - a) + a + 1 << endl;
          else cout << (long long)(n + 1 - a) / 2 * (b - a) + a << endl;
        }
    }
}