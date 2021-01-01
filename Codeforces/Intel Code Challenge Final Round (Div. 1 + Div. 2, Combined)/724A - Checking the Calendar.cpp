#include <bits/stdc++.h>
using namespace std;

string date[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int get(string a) {
  int res = 0;
  for (; res < 7; res++) {
    if (date[res] == a) {
      return res;
    }
  }
}

int main() {
  string a, b;
  cin >> a >> b;
  int id1 = get(a), id2 = get(b);
  if (((id2 - id1) + 7) % 7 == 0 || ((id2 - id1) + 7) % 7 == 2 || ((id2 - id1) + 7) % 7 == 3) {
    cout << "YES" << endl;
  } else cout << "NO" << endl;
  return 0;
}
