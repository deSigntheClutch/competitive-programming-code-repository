#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 5;

int n;
string s;

int main() {
      int T; cin >> T; while (T--) {
            cin >> s;

            int cnt0 = 0, cnt1 = 0;
            for (char c : s) {
                  if (c == '0') cnt0 += 1;
                  else cnt1 += 1;
            }

            cout << cnt1 << endl;
      }
      return 0;
}
