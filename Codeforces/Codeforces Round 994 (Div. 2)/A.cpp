#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 4;
const long long INF = 1e10 + 1;

int n;
int T;
int a[N];

int main() {
      cin >> T;
      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
            }

            int cnt = 0;

            for (int i = 1; i <= n; i++) {
                  if (a[i] == 0) continue;
                  int pt = i;
                  while(pt <= n && a[pt] != 0) pt += 1;
                  cnt += 1;
                  i = pt - 1;
            }

            if (cnt >= 2) cout << 2 << endl;
            else if (cnt == 1) cout << 1 << endl;
            else cout << 0 << endl;
      }
}
