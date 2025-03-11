#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 26 - 1;

int n;

int main() {

      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<int> dist(0, 25);

      cin >> n;
      string s = "";
      for (int i = 0; i < 10; i++) {
            s += ('a' + dist(gen));
      }
      cout << s << endl;

      for (int i = 0; i < n - 1; i++) {
            char c = 'a' + (s[i % 10] + dist(gen)) % 26;
            if (c == s[i % 10]) {
                  s[i % 10] = 'a' + (s[i % 10] - 'a' + 1) % 26;
            } else {
                  s[i % 10] = c;
            }
            cout << s << endl;
      }
      return 0;
}
