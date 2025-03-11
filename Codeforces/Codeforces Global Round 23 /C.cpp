#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N], ans[N];

int main() {

      int T; cin >> T;

      while (T--) {
            cin >> n;
            for (int i = 1; i <= n; i++) {
                  cin >> a[i];
                  ans[i] = 0;
            }
            set<int> s;
            set<int> v;
            for (int i = 1; i <= n; i++) {
                  s.insert(i);
                  v.insert(i);
            }

            for (int i = 1; i < n; i++) {
                  s.erase(a[i]);

                  int minVal = *s.begin();
                  int diff = a[i] - minVal;

                  if (diff > 0) {
                        int add = *v.lower_bound(diff);
                        ans[add] = i + 1;
                        v.erase(add);
                  }
            }

            for (int i = 1; i <= n; i++) {
                  if (ans[i] == 0) {
                        cout << 1 << " ";
                  } else {
                        cout << ans[i] << " ";
                  }
            }
            cout << endl;
      }

      return 0;
}