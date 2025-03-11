#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int INF = 2e5 + 10;
int n, k;
int a[N], b[N];

void check(vector<int> x) {
      for (int i = 1; i <= n; i++) {
            b[i] = a[i];
      }

      for (int y : x) {
            swap(b[y], b[y + 1]);
            b[y] += k;
      }

      for (int i = 1; i <= n; i++) {
            cout << b[i] << " ";
      }
      cout << endl;
}


int main() {
      cin >> n >> k;
      for (int i = 1; i <= n; i++) cin >> a[i];

      if (n == 2) {
            if (a[1] > a[2] && a[2] + k <= a[1]) {
                  cout << "Yes" << endl << 1 << endl << 1 << endl;
            } else if (a[1] <= a[2]) {
                  cout << "Yes" << endl << 0 << endl;
            } else {
                  cout << "No" << endl;
            }
            return 0;
      }

      vector<int> ans;

      for (int i = 2; i < n; i++) {
            for (int j = 0; j < 204 * (i / 2); j++) {
                  ans.push_back(i);
            }
      }

      for (int j = 0; j < 204 * (n + 1); j++) {
            ans.push_back(n - 1);
      }

      if (n > 3) {
            ans.push_back(n - 1);
            cout << "Yes" << endl;
            assert(ans.size() <= 500000);
            cout << ans.size() << endl;
            for (int x: ans) cout << x << " ";
            cout << endl;
      } else {
            if (a[2] > a[3] && a[3] + k <= a[2]) {
                  ans.push_back(2);
                  cout << "Yes" << endl;
                  cout << ans.size() << endl;
                  for (int x: ans) cout << x << " ";
                  cout << endl;
            } else if (a[2] <= a[3]) {
                  cout << "Yes" << endl;
                  cout << ans.size() << endl;
                  for (int x: ans) cout << x << " ";
                  cout << endl;
                  //return 0;
            } else {
                  for (int j = 0; j < 102; j++) {
                        ans.push_back(1);
                  }
                  ans.push_back(2);
                  cout << "Yes" << endl;
                  cout << ans.size() << endl;
                  for (int x: ans) cout << x << " ";
                  cout << endl;
                  //return 0;
            }
      }
      //check(ans);

      return 0;
}