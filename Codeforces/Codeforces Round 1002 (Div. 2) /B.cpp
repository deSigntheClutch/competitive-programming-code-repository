#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5;

int n, k;
int a[N];


int cal(vector<int> x) {
      int res = 1;

      x.push_back(0);

      for (int i = 0; i < x.size(); i++) {
            if (i + 1 == x[i]) {
                  res += 1;
            } else {
                  break;
            }
      }
      return res;
}

int main() {
      int T; cin >> T; while (T--) {
            cin >> n >> k;

            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
            }

            if (k == n) {
                  vector<int> b;
                  for (int i = 2; i <= n; i += 2) {
                        b.push_back(a[i]);
                  }
                  cout << cal(b) << endl;
            } else {
                  bool flag = false;
                  for (int i = 2; i <= n - k + 2; i++) {
                        if (a[i] != 1) flag = true;
                  }

                  if (flag) cout << "1" << endl;
                  else cout << 2 << endl;
            }
      }
      return 0;
}
