#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

struct Polynomial {
  vector<int> digit;
  void __reverse() {
    for (int i = 0; i < (int)digit.size(); i++) {
      digit[i] *= -1;
    }
  }
  bool check() {
    for (int i = 0; i < (int)digit.size(); i++) {
      if (abs(digit[i]) >= 2) return false;
    }
    return true;
  }
} a, b;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  a.digit.resize(2);
  b.digit.resize(1);
  a.digit[0] = 0, a.digit[1] = 1;
  b.digit[0] = 1;
  while (--n) {
    Polynomial c, d;
    c.digit.resize((int)a.digit.size() + 1);
    d.digit.resize((int)a.digit.size() + 1);
    for (int i = 0; i < (int)a.digit.size(); i++) {
      c.digit[i + 1] = -a.digit[i];
      d.digit[i + 1] = a.digit[i];
    }
    for (int i = 0; i < (int)b.digit.size(); i++) {
      c.digit[i] += b.digit[i];
      d.digit[i] += b.digit[i];
    }
    int bit = c.digit[c.digit.size() - 1];
    if (bit == -1) c.__reverse();
    bit = d.digit[d.digit.size() - 1];
    if (bit == -1) d.__reverse();

    if (c.check()) {
      b.digit.resize((int)a.digit.size());
      b = a;
      a.digit.resize((int)c.digit.size());
      a = c;
    } else if (d.check()) {
      b.digit.resize((int)a.digit.size());
      b = a;
      a.digit.resize((int)d.digit.size());
      a = d;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << (int)a.digit.size() - 1 << endl;
  for (int i = 0; i < a.digit.size(); i++) {
    cout << a.digit[i] << " ";
  }
  cout << endl;
  cout << (int)b.digit.size() - 1 << endl;
  for (int i = 0; i < b.digit.size(); i++)  {
    cout << b.digit[i] << " ";
  }
  cout << endl;
  return 0;
}
