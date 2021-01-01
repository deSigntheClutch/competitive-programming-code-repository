#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, k;
string name[1234];
string a[55];

int main() {
  for (int i = 0; i < 26; i++) {
    name[i] = (char)('A' + i);
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26 ; j++) {
      name[26 + 26 * i + j] += (char)('A' + i);
      name[26 + 26 * i + j] += (char)('a' + j);
    }
  }
  int u = 0;
  cin >> n >> k;
  for (int i = 1; i < k; i++) {
    a[i] = name[u++];
    cout << a[i] << " ";
  }
  for (int i = k; i <= n; i++) {
    string status;
    cin >> status;
    if (status == "YES") {
      a[i] = name[u++];
    } else {
      a[i] = a[i - k + 1];
    }
    cout << a[i] << " ";
  }
  cout << endl;
  return 0;
}


