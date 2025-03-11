#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 3;

int main() {
      int n;
      string s[N];
      cin >> n;

      for (int i = 1; i <= 3; i++) cin >> s[i];

      int cnt = 0;
      for (int i = 1; i <= n; i++) {
            set<char> sc;

            for (int j = 1; j <= 3; j++) {
                  sc.insert(s[j][i - 1]);
            }
            cnt += sc.size() - 1;
      }
      cout << cnt << endl;
      return 0;
}