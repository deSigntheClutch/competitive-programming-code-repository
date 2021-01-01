#include <bits/stdc++.h>
using namespace std;

const int N = 2e2 + 10;

int n, k;
int a[N], b[N];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < k; i++) {
    cin >> b[i];
  }
  if(k >= 2) {
    cout << "Yes" << endl;
  } else {
    for(int i = 0; i < n; i++) {
      if(a[i] == 0) a[i] = b[0];
    }
    for(int i = 0; i < n - 1; i++) {
      if(a[i] > a[i + 1]) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }
  return 0;
}
