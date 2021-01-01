#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;

int main() {
  cin >> n;
  for(int i = 1;;i++) {
    if(n <= (long long)i * (i + 1) / 2) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
