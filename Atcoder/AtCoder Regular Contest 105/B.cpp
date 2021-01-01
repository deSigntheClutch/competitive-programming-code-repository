#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
map<int, int> C;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];    
  }
  int gcc = a[1];
  for (int i = 2; i <= n; i++) {
      gcc = __gcd(a[i], gcc);
  }
  cout << gcc << endl;
  return 0;
}
