#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e10 + 1;

int n;
int T;
int a[N];
string s;

int main() {
      cin >> T;
      while (T--) {
            cin >> n >> s;
            int cntP = 0;
            int cntS = 0;
            for (int i = 1; i <= n; i++) {
                  cntP += s[i - 1] == 'p';
                  cntS += s[i - 1] == 's';
            }

            if (cntP == 0 || cntS == 0) {
                  cout << "YES" << endl;
            } else if (cntP == 1 && cntS > 1) {
                  if (s[n - 1] != 'p') {
                        cout << "NO" << endl;
                  } else {
                        cout << "YES" << endl;
                  }
            } else if (cntS == 1 && cntP > 1) {
                  if (s[0] != 's') {
                        cout << "NO" << endl;
                  } else {
                        cout << "YES" << endl;
                  }
            } else if (cntS == 1 && cntP == 1) {
                  if (s[0] == 's' || s[n - 1] == 'p') {
                        cout << "YES" << endl;
                  } else {
                        cout << "NO" << endl;
                  }
            }
            else {
                  cout << "NO" << endl;
            }
      }
}
